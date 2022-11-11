#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <arpa/inet.h>

int s_sock;
struct sockaddr_in sender_addr;
const char* data = "w";



int main() {
    sender_addr.sin_family = AF_INET;
    sender_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    sender_addr.sin_port = htons(8888);

    s_sock = socket(AF_INET, SOCK_STREAM, 0);


    connect(s_sock, &sender_addr, sizeof(sender_addr));
    send(s_sock, data, 1, 0);

    close(s_sock);
}
