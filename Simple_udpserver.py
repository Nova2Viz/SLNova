#simple server udp 
import socket#import socket module
#define the udp ip address and port number
udpip="10.1.24.121"
udpport=6002
serverSock=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)#create the datagram socket
serverSock.bind((udpip,udpport))#Bind to ip and port
print("server is waiting")#Listening for incoming datagrams
while True:
  data,addr=serverSock.recvfrom(1024)#receive the client packet along with the address it is coming from
  print("Message",data)
