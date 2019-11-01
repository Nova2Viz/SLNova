#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<unistd.h>
#include<sys/select.h>
#include<arpa/inet.h>

#define MYPORT 4444
#define STDIN 0

int main()
{
	int serverfd = socket(AF_INET,SOCK_STREAM,0);
	if(serverfd == -1)
	{
		perror("Socket error");
		exit(1);
	}
	
	char rd[50],wr[50];
	
	struct sockaddr_in server,client;
	server.sin_family = AF_INET;
	server.sin_port = htons(MYPORT);
	server.sin_addr.s_addr = INADDR_ANY;
	
	int b = bind(serverfd,(struct sockaddr *)&server,sizeof(struct sockaddr));
	if(b== -1)
	{
		perror("Bind error");
		exit(1);
	}
	
	int size = sizeof(struct sockaddr);
	fd_set copyfd,readfd;
	
	FD_ZERO(&copyfd);
	FD_ZERO(&readfd);
	
	listen(serverfd,5);
	
	int clientfd = accept(serverfd,(struct sockaddr *)&client,&size);
	
	if(clientfd == -1)
	{
		perror("Accept error");
		exit(1);
	}
	
	printf("Incoming connection accepted from %s\n",inet_ntoa(client.sin_addr));
	
	FD_SET(STDIN,&readfd);
	FD_SET(clientfd,&readfd);
	
	struct timeval tm;
	while(1)
	{
		copyfd = readfd;
		tm.tv_sec = 5;
		tm.tv_usec = 4000000;
		int ret = select(clientfd+1,&copyfd,NULL,NULL,&tm);
		if(ret == -1)
		{
			perror("Select error");
			exit(1);
		}
		
		if(ret == 0)
		{
			printf(" ");
		}
		else
		{
			if(FD_ISSET(clientfd,&copyfd))
			{
				int r = recv(clientfd,rd,sizeof(rd),0);
				rd[r] = '\0';
				printf(" %s\n",rd);
			}
			
			if(FD_ISSET(STDIN,&copyfd))
			{
				scanf("%s",wr);
				send(clientfd,wr,strlen(wr),0);
			}
		}
	}
	close(clientfd);
	close(serverfd);
}

			
