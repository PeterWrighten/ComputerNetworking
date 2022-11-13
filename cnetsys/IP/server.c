#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <unistd.h>
#define BUFFER_SIZE 1024
#include <arpa/inet.h>

int l_sock, d_sock;
struct sockaddr_in sender_addr;
struct sockaddr_in recv_addr;
char buffer[BUFFER_SIZE];

int main() {
    sender_addr.sin_family = AF_INET;
    sender_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    sender_addr.sin_port = htons(8888); 

    l_sock = socket(AF_INET, SOCK_STREAM, 0);
    bind(l_sock, &sender_addr, sizeof(sender_addr));
    while(1) {
        if(listen(l_sock, 1) > 0) {    
            d_sock = accept(l_sock, &recv_addr, sizeof(recv_addr));

            int n = recv(d_sock, buffer, BUFFER_SIZE, 0);

        
            printf("%s", buffer);
            break;
        }
    }

    close(d_sock);
}
