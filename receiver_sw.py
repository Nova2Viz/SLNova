#stop and wait receiver-udp
import socket
serverport =5100
serversocket = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
serversocket.bind(('127.0.0.1',serverport))
count="0"
while True:
	acknowledged=False
	while not acknowledged:
		ACK,addr =serversocket.recvfrom(2048)
		print("FRAME RECEIVED:"+str(ACK))
		acknowledged=True
		
		if "1" in str(ACK):
			count="0"
		else:
			count="1"
		msg=str.encode(count)
		serversocket.sendto(msg,addr)
serversocket.close()
