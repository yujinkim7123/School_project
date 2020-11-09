from socket import *
import select
import time

port = 3333
BUFSIZE = 1024

clients = []


s_sock = socket(AF_INET, SOCK_STREAM)
s_sock.bind(('', port))
s_sock.listen(1)

clients.append(s_sock)

while True:
    
    r_sock, w_sock, e_sock = select.select(clients, [], [])

    for s in r_sock:
        if s == s_sock:
            c_sock, addr = s_sock.accept()
            clients.append(c_sock)
            print("new client", addr)

        else:
            data = s.recv(BUFSIZE)

            if not data:
                s.close()
                clients.remove(s)
                continue
            
            print(time.asctime() + str(addr) + ':' + data.decode())
            
            for client in clients:
                if client != s and client != s_sock:
                    client.send(data)
