#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>

#define MYPORT 3490
#define SIZE_TO_SEND 1000
#define MY_IP "127.0.0.1"

int main(int argc, char *argv[]) {
 int sockfd,sockfd2;
 char tosend = 'y';
 char ack;
 struct sockaddr_in my_addr,rcvr_addr;
 struct timeval start,end;
 int sin_size = sizeof(my_addr),i,k,num_packet_sent,optval,j;
 double t1,t2;


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
 t1=0.0; t2=0.0;
 printf("Sending 1000 messages 1 byte each and wait for ack.\n");
 for(num_packet_sent=0;num_packet_sent<1000;num_packet_sent++){
  if(gettimeofday(&start,NULL)) {
   printf("time failed\n");
   exit(1);
  }
  send(sockfd2,&tosend,sizeof(char),0);
  //printf("%c",tosend);
  optval=recv(sockfd2,&ack,sizeof(char),0);
  if(optval==-1) {
   perror("Receive error");
   exit(1);
  }
  else{
   if(gettimeofday(&end,NULL)) {
    printf("time failed\n");
    exit(1);
   }
             t1+=start.tv_sec+(start.tv_usec/1000000.0);
             t2+=end.tv_sec+(end.tv_usec/1000000.0);
  }
 }

 printf("RTT for 1 byte message = %g ms\n",(t2-t1)/1000);
 printf("Network throughput for 1 byte message = %g Mbps\n\n\n",(8.192/(t2-t1)));
 ////////////////////////////////////////////////////////////////////////////////
 t1=0.0; t2=0.0;
 printf("Sending 1000 messages 1 KB each and wait for ack.\n");
 for(num_packet_sent=0;num_packet_sent<1000;num_packet_sent++){
 for(j=0;j<1024;j++)
  {
  if(gettimeofday(&start,NULL)) {
   printf("time failed\n");
   exit(1);
  }
  
  	send(sockfd2,&tosend,sizeof(char),0);
 	 //printf("%c",tosend);
  	optval=recv(sockfd2,&ack,sizeof(char),0);
 	 if(optval==-1) {
  	 perror("Receive error");
  	 exit(1);
  	}
 	 else{
  		 if(gettimeofday(&end,NULL)) {
   		 printf("time failed\n");
   		 exit(1);
  		 }
  		 }
             t1+=start.tv_sec+(start.tv_usec/1000000.0);
             t2+=end.tv_sec+(end.tv_usec/1000000.0);
  	}}
 

 printf("RTT for 1 KB = %g ms\n",(t2-t1)/1000);
 printf("Network throughput for 1 KB message = %g Mbps\n\n\n",(8192/(t2-t1)));
 /////////////////////////////////////////////////////////////////////////////////
 t1=0.0; t2=0.0;
 printf("Sending 1000 messages 2 KB each and wait for ack.\n");
 for(num_packet_sent=0;num_packet_sent<1000;num_packet_sent++){
 for(j=0;j<2048;j++)
  {
  if(gettimeofday(&start,NULL)) {
   printf("time failed\n");
   exit(1);
  }
  
  	send(sockfd2,&tosend,sizeof(char),0);
 	// printf("%c",tosend);
  	optval=recv(sockfd2,&ack,sizeof(char),0);
 	 if(optval==-1) {
  	 perror("Receive error");
  	 exit(1);
  	}
 	 else{
  		 if(gettimeofday(&end,NULL)) {
   		 printf("time failed\n");
   		 exit(1);
  		 }
  		 }
             t1+=start.tv_sec+(start.tv_usec/1000000.0);
             t2+=end.tv_sec+(end.tv_usec/1000000.0);
  	}}
 

 printf("RTT for 2 KB = %g ms\n",(t2-t1)/1000);
 printf("Network throughput for 2 KB message = %g Mbps\n\n\n",((2*8192)/(t2-t1)));
 /////////////////////////////////////////////////////////////////////////////
 t1=0.0; t2=0.0;
 printf("Sending 1000 messages 4 KB each and wait for ack.\n");
 for(num_packet_sent=0;num_packet_sent<1000;num_packet_sent++){
 for(j=0;j<4096;j++)
  {
  if(gettimeofday(&start,NULL)) {
   printf("time failed\n");
   exit(1);
  }
  
  	send(sockfd2,&tosend,sizeof(char),0);
 	// printf("%c",tosend);
  	optval=recv(sockfd2,&ack,sizeof(char),0);
 	 if(optval==-1) {
  	 perror("Receive error");
  	 exit(1);
  	}
 	 else{
  		 if(gettimeofday(&end,NULL)) {
   		 printf("time failed\n");
   		 exit(1);
  		 }
  		 }
             t1+=start.tv_sec+(start.tv_usec/1000000.0);
             t2+=end.tv_sec+(end.tv_usec/1000000.0);
  	}}
 

 printf("RTT for 4 KB = %g ms\n",(t2-t1)/1000);
 printf("Network throughput for 4 KB message = %g Mbps\n\n\n",((4*8192)/(t2-t1)));
 /////////////////////////////////////////////////////////////////////////////
 t1=0.0; t2=0.0;
 printf("Sending 1000 messages 8 KB each and wait for ack.\n");
 for(num_packet_sent=0;num_packet_sent<1000;num_packet_sent++){
 for(j=0;j<8192;j++)
  {
  if(gettimeofday(&start,NULL)) {
   printf("time failed\n");
   exit(1);
  }
  
  	send(sockfd2,&tosend,sizeof(char),0);
 	// printf("%c",tosend);
  	optval=recv(sockfd2,&ack,sizeof(char),0);
 	 if(optval==-1) {
  	 perror("Receive error");
  	 exit(1);
  	}
 	 else{
  		 if(gettimeofday(&end,NULL)) {
   		 printf("time failed\n");
   		 exit(1);
  		 }
  		 }
             t1+=start.tv_sec+(start.tv_usec/1000000.0);
             t2+=end.tv_sec+(end.tv_usec/1000000.0);
  	}}
 

 printf("RTT for 8 KB = %g ms\n",(t2-t1)/1000);
 printf("Network throughput for 8 KB message = %g Mbps\n\n\n",((8*8192)/(t2-t1)));
 /////////////////////////////////////////////////////////////////////////////
 t1=0.0; t2=0.0;
 printf("Sending 1000 messages 16 KB each and wait for ack.\n");
 for(num_packet_sent=0;num_packet_sent<1000;num_packet_sent++){
 for(j=0;j<16384;j++)
  {
  if(gettimeofday(&start,NULL)) {
   printf("time failed\n");
   exit(1);
  }
  
  	send(sockfd2,&tosend,sizeof(char),0);
 	// printf("%c",tosend);
  	optval=recv(sockfd2,&ack,sizeof(char),0);
 	 if(optval==-1) {
  	 perror("Receive error");
  	 exit(1);
  	}
 	 else{
  		 if(gettimeofday(&end,NULL)) {
   		 printf("time failed\n");
   		 exit(1);
  		 }
  		 }
             t1+=start.tv_sec+(start.tv_usec/1000000.0);
             t2+=end.tv_sec+(end.tv_usec/1000000.0);
  	}}
 

 printf("RTT for 16 KB = %g ms\n",(t2-t1)/1000);
 printf("Network throughput for 16 KB message = %g Mbps\n\n\n",((16*8192)/(t2-t1)));
 /////////////////////////////////////////////////////////////////////////////
 printf("\nclose sockets and exit\n");
 shutdown(sockfd2,2);
 shutdown(sockfd,2);
 exit(0);
}

