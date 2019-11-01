#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#define MYPORT 3490
#define SIZE_TO_SEND 1000
#define MY_IP "127.0.0.1"

int main(int argc, char *argv[]) {
 int sockfd,sockfd2;
 int tosend = 0;
 char ack;
 struct sockaddr_in my_addr,rcvr_addr;
 struct timeval start,end;
 int sin_size = sizeof(my_addr),i,k,num_packet_sent,optval,j;


 if( (sockfd = socket(PF_INET, SOCK_STREAM, 0)) ==-1){
  perror("socket error");
  exit(1);
 }
 my_addr.sin_family = AF_INET;
 my_addr.sin_port = htons(MYPORT);  
 my_addr.sin_addr.s_addr = inet_addr(MY_IP);
 memset(my_addr.sin_zero, '\0', sizeof(my_addr.sin_zero));

 optval = 1;
 if (setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&optval,sizeof(int)) == -1) {
  perror("setsockopt");
  exit(1);
 }

 if (bind(sockfd, (struct sockaddr *)&my_addr, sizeof my_addr) == -1) {
  perror("bind");
  exit(1);	
 }
 listen(sockfd,10);

 sockfd2 = accept(sockfd, (struct sockaddr *)&rcvr_addr, &sin_size);
///////////////////////////////////////////////////////////////////////////////////////

 
 for(num_packet_sent=0;num_packet_sent<100;num_packet_sent++){
 
 	sleep(1);
 
 
  if(gettimeofday(&start,NULL)) {
   printf("time failed\n");
   exit(1);
  }
  send(sockfd2,&tosend,sizeof(int),0);
  printf("Send %d\n",tosend);
  optval=recv(sockfd2,&ack,sizeof(int),0);
  if(optval==-1) {
   perror("Receive error");
   exit(1);
  }
  else{
   printf("Ack %d\n",ack);
   tosend = ack;
   if(gettimeofday(&end,NULL)) {
    printf("time failed\n");
    exit(1);
   }

            
  }
 }

 
 printf("\nclose sockets and exit\n");
 shutdown(sockfd2,2);
 shutdown(sockfd,2);
 exit(0);
}

