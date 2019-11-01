#include<netinet/in.h>
#include<sys/socket.h>
#include<stdio.h>
main()
{
struct sockaddr_in sa;
int sockfd;
char buff[100];
sockfd=socket(AF_INET,SOCK_STREAM,0);
sa.sin_family=AF_INET;
sa.sin_port=htons(5600);
sa.sin_addr.s_addr = inet_addr("127.0.0.1"); 
connect(sockfd,(struct sockaddr*)&sa,sizeof(sa));
read(sockfd,buff,sizeof(buff));
printf("\nMessage Read %s",buff);
}
 
