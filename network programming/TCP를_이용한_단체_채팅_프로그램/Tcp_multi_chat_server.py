from socket import *
import threading
import time

port = 3333
BUFSIZE = 1024

clients = []

def recv(sock):
    
    while True:
        data = sock.recv(BUFSIZE)

        if not data:
            break

        print(time.asctime() + str(addr) + ':' + data.decode())

        for client in clients:
            if client !=  sock:
                client.send(data)

    sock.close()




s = socket(AF_INET, SOCK_STREAM)
s.bind(('', port))
s.listen(1)

while True:
    sock,addr = s.accept()

    if sock not in clients:
        print("new client", addr)
        clients.append(sock)
    
    th = threading.Thread(target=recv, args=(sock,))
    th.start()
    
