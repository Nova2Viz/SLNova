#simple client udp
import socket#import socket module
#define the udp ip and port number
udpip="10.1.24.121"
udpport=6002
Message=("hii")
bytesToSend=str.encode(Message)
clientSock=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)#create a udp datagram socket
clientSock.sendto(bytesToSend,(udpip,udpport))#send the data to server using created udp socket
