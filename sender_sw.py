#stop and wait sender-udp
import socket
client= socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
client.bind(('127.0.0.1',5011))
dest=('127.0.0.1',5100)
user=input(">> ")
user_input=str.encode(user)
while user_input:
	client.sendto(user_input,dest)
	val,address = client.recvfrom(2048)
	print ("EXPECTING FRAME:"+str(val))
	user=input(">> ")
	user_input=str.encode(user)
client.close()
