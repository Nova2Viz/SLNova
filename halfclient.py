#half duplex communication client-tcp
import socket
serverport = 6004
clientsocket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
clientsocket.connect(('10.1.24.121',serverport))
while True:
  sentence = input(">> ")
  clientsocket.send(sentence.encode())
  message = clientsocket.recv(2048)
  print (">> ", message.decode())
  if(sentence == "disconnect"):
    break
print("BYEE SERVER")
clientsocket.close()
