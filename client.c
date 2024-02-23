#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>
#define MAXSIZE 50

int main()
{
    int sockfd, retval;
    int recedbytes, sentbytes;
    struct sockaddr_in serveraddr;
    char buff[MAXSIZE];
    int port;

    FILE *file = fopen("port.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    fscanf(file, "%d", &port);
    fclose(file);
    printf("PORT: %d\n", port);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("\nSocket Creation Error");
    }
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(port);
    serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    retval = connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
    if (retval == -1)
    {
        printf("Connection error");
    }
    printf("enter the text\n");

    scanf("%s", buff);

    sentbytes = send(sockfd, buff, sizeof(buff), 0);

    if (sentbytes == -1)
    {
        printf("!!");
        close(sockfd);
    }
    recedbytes = recv(sockfd, buff, sizeof(buff), 0);
    puts(buff);
    close(sockfd);
    return 0;
}
