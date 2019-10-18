#half duplex communication server-tcp
import socket
serverport = 6004
serversocket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
serversocket.bind(('10.1.24.121',serverport))
serversocket.listen(1)
print ("Welcome: The server is now ready to receive")
client, address = serversocket.accept()
print("Got a connection from",address[0],address[1])
while True:
  sentence = client.recv(2048).decode()
  print("RECEIVED DATA FROM THE CLIENT")
  print(sentence)
  message = input(">> ")
  print("REPLY IS SENT")
  client.send(message.encode())
  if(message == "disconnect"):
    break
client.close()
print("GOOD BYE")
