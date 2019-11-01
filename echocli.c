#include <string.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>

#define SENDER_PORT 3490
#define SENDER_IP "127.0.0.1"

int main(int argc, char *argv[]) {

 int sockfd;
 int rcv_num,loop_count,i,j;
 char buf;
 struct sockaddr_in sender_addr;


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
 printf("Receive 1000 packets of 1 byte and send then back\n");
 for(i=0;i<1000;i++){
  rcv_num = recv(sockfd,&buf,sizeof(char),0);
  //printf("%c",buf);
  if(rcv_num!=0) {
   
   send(sockfd,&buf,sizeof(char),0);
   
  }
  else{ 
   perror("Receive error");
   exit(1);
  }
 }
 /////////////////////////////////////////////////////////////////
  printf("Receive 1000 packets of 1 KB and send then back\n");
 for(i=0;i<1000;i++){
 for(j=0;j<1024;j++){
  rcv_num = recv(sockfd,&buf,sizeof(char),0);
  //printf("%c",buf);
  if(rcv_num!=0) {
   
   send(sockfd,&buf,sizeof(char),0);
   
  }
  else{ 
   perror("Receive error");
   exit(1);
  }}
 }
 ////////////////////////////////////////////////////////////////////
  printf("Receive 1000 packets of 2 KB and send then back\n");
 for(i=0;i<1000;i++){
 for(j=0;j<2048;j++){
  rcv_num = recv(sockfd,&buf,sizeof(char),0);
 // printf("%c",buf);
  if(rcv_num!=0) {
   
   send(sockfd,&buf,sizeof(char),0);
   
  }
  else{ 
   perror("Receive error");
   exit(1);
  }}
 }
 /////////////////////////////////////////////////////////////////
 printf("Receive 1000 packets of 4 KB and send then back\n");
 for(i=0;i<1000;i++){
 for(j=0;j<4096;j++){
  rcv_num = recv(sockfd,&buf,sizeof(char),0);
 // printf("%c",buf);
  if(rcv_num!=0) {
   
   send(sockfd,&buf,sizeof(char),0);
   
  }
  else{ 
   perror("Receive error");
   exit(1);
  }}
 }
 ///////////////////////////////////////////////////////////////
 printf("Receive 1000 packets of 8 KB and send then back\n");
 for(i=0;i<1000;i++){
 for(j=0;j<8192;j++){
  rcv_num = recv(sockfd,&buf,sizeof(char),0);
 // printf("%c",buf);
  if(rcv_num!=0) {
   
   send(sockfd,&buf,sizeof(char),0);
   
  }
  else{ 
   perror("Receive error");
   exit(1);
  }}
 }
 ///////////////////////////////////////////////////////////////
 printf("Receive 1000 packets of 16 KB and send then back\n");
 for(i=0;i<1000;i++){
 for(j=0;j<16384;j++){
  rcv_num = recv(sockfd,&buf,sizeof(char),0);
 // printf("%c",buf);
  if(rcv_num!=0) {
   
   send(sockfd,&buf,sizeof(char),0);
   
  }
  else{ 
   perror("Receive error");
   exit(1);
  }}
 }
 ///////////////////////////////////////////////////////////////
 printf("\tDone\nClose socket and exit\n");
 close(sockfd);
 exit(0);
}
