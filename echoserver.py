#echo server-udp
import socket#import socket module
#define the udp ip and port number
udpip="10.1.24.121"
udpport=6002
serverSock=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)#create a datagram socket
serverSock.bind((udpip,udpport))#bind to ip and port
print("server is waiting")#Listening for incoming datagrams
while True:
	cdata,addr=serverSock.recvfrom(1024)#receive the client packets along with the address it is coming from
	print(cdata)
	print(addr)
	serverSock.sendto(cdata,addr)#send the data to the client
