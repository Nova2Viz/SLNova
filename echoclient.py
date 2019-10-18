#echo client - udp
import socket#import socket module
#here we define the udp ip address as well as port number
udpip="10.1.24.122"
udpport=6789
Message=("hii from client")
bytesToSend=str.encode(Message)
clientSock=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)#create a datagram socket
clientSock.sendto(bytesToSend,(udpip,udpport))#send the data to server
data=clientSock.recvfrom(1024)#message received from server along with the address it is coming from
print(data)
       
