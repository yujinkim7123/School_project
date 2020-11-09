from socket import *
import selectors
import sys

BUF_SIZE = 1024
LENGTH = 10


sel = selectors.DefaultSelector()


def read(conn, mask):
    data = conn.recv(1024)
    if not data:
        sel.unregister(conn)
        conn.close()
        return
    print('recvived data:', data.decode())
    f = open('devicedata.txt' , 'ab')
    f.write(data)
    f.write(b'\n')
    f.close()


s1 = socket(AF_INET, SOCK_STREAM)
s1.connect(('localhost',7777))
s1.send('Register'.encode())
sel.register(s1, selectors.EVENT_READ, read)

s2 = socket(AF_INET, SOCK_STREAM)
s2.connect(('localhost',8888))
s2.send('Register'.encode())
sel.register(s2, selectors.EVENT_READ, read)

while True:
    events = sel.select()

    for key, mask in events:
            callback = key.data
            callback(key.fileobj, mask)
 
