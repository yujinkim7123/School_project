from socket import *


BUFF_SIZE = 1024
port = 5555

c_sock = socket(AF_INET, SOCK_DGRAM)

while True:
    msg = input('Enter the message("send mboxId message" or "receive mboxId"):')
    c_sock.sendto(msg.encode(),('localhost', port))
    if msg == 'quit':
        c_sock.close()
        break
    data, addr = c_sock.recvfrom(BUFF_SIZE)
    print(data.decode())
    
