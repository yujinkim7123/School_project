import socket
import threading

BUFSIZE = 1024

def handler(sock):
    while True:
        msg = sock.recv(BUFSIZE)
        print(msg.decode())


sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.connect(('localhost', 3333))


my_id = input('ID를 입력하세요: ')
sock.send(('['+ my_id + ']').encode())

th = threading.Thread(target=handler, args=(sock,))
th.daemon = True
th.start()


while True:
    msg = '[' + my_id + ']' + input()
    sock.send(msg.encode())
    
