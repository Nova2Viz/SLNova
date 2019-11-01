#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main()
{
	
	int sockfd;
	struct sockaddr_in si_me,si_other;
	//////////////////////////////////////////////////////
	int a,b;
	char c;
	int res;
	//////////////////////////////////////////////////////
	socklen_t addr_size;
	addr_size = sizeof(si_other);
	sockfd = socket(AF_INET,SOCK_DGRAM,0);
	
	
	si_me.sin_family = AF_INET;
	si_me.sin_port = htons(5000);
	si_me.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	bind(sockfd,(struct sockaddr *)&si_me,sizeof(si_me));
	
	
	
	recvfrom(sockfd,&a,sizeof(int),0,(struct sockaddr *)&si_other,&addr_size);
	
	recvfrom(sockfd,&b,sizeof(int),0,(struct sockaddr *)&si_other,&addr_size);

	recvfrom(sockfd,&c,sizeof(char),0,(struct sockaddr *)&si_other,&addr_size);

	
	if(c == '*')
		res = a * b;
	if(c == '+')
		res = a + b;
    if(c == '-')
		res = a - b;
	
	if(c == '/')
		res = a / b;
		
	sendto(sockfd,&res,sizeof(int),0,(struct sockaddr*)&si_other,addr_size);
	
}

