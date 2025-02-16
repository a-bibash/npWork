#include <stdio.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>

#define MAXLINE 1024
#define LISTENQ 10
typedef struct sockaddr SA;
int main(int argc, char **argv)
{
   int sockfd, n;
   struct sockaddr_in servaddr;

   int port;
   char buffe[MAXLINE + 1];
   char message[MAXLINE];
   int a;
   if (argc != 3)
      printf("usage:a.out <IPaddress> <port>");
   if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
      printf("socket error");
   port = atoi(argv[2]);
   bzero(&servaddr, sizeof(servaddr));
   servaddr.sin_family = AF_INET;
   servaddr.sin_port = htons(port);
   if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
      printf("inet_pton error for %s", argv[1]);

   if (connect(sockfd, (SA *)&servaddr, sizeof(servaddr)) < 0)
      printf("connection error");

   while (1)
   {
      printf("Enter a msg to send to server\n");
      fgets(message, sizeof(message), stdin);
      write(sockfd, message, sizeof(message));

 read(sockfd,buffe,sizeof(buffe);

 printf("From Server:\n");

 fputs(buffe,stdout);
   }
}
close(sockfd);
}
