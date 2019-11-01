#include <string.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>

#define SENDER_PORT 3490
#define SENDER_IP "127.0.0.1"

int main(int argc, char *argv[]) {

 int sockfd;
 int rcv_num,loop_count,i,j;
 int buf;
 struct sockaddr_in sender_addr;
struct timeval start,end;
double t1,t2;

 if( (sockfd = socket(PF_INET, SOCK_STREAM, 0)) ==-1){
  perror("socket error"); 
  exit(1);
 }

 sender_addr.sin_family = AF_INET;
 sender_addr.sin_port = htons(SENDER_PORT);
 sender_addr.sin_addr.s_addr = inet_addr(SENDER_IP);
 memset(sender_addr.sin_zero, '\0', sizeof(sender_addr.sin_zero));

 if ((connect(sockfd,(struct sockaddr *)&sender_addr,sizeof(sender_addr))) ==-1){
  perror("connect error"); 
  exit(1);
 }


 printf("Connection to sender established\n");
////////////////////////////////////////////////////////////////////

 for(i=0;i<100;i++){

 gettimeofday(&start,NULL);
 t1 = start.tv_sec;
 
 //printf("Time  %d AND  %d\n",start.tv_sec,start.tv_usec);
  rcv_num = recv(sockfd,&buf,sizeof(int),0);
  gettimeofday(&end,NULL);
  t2 = end.tv_sec;
  
  if(t2 - t1 > 2)
  {
  	printf("Ponna packet vara late aachu\n");
  }
 

  if(rcv_num!=0) {
     printf("Received %d\n",buf);
  buf = buf + 1;
   send(sockfd,&buf,sizeof(int),0);
   
  }
  

 }
 
 printf("\tDone\nClose socket and exit\n");
 close(sockfd);
 exit(0);
}
