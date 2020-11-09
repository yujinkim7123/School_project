from socket import *
import sys

BUF_SIZE = 1024
LENGTH = 10

s1 = socket(AF_INET, SOCK_STREAM)
s1.connect(('localhost',7777))
s2 = socket(AF_INET, SOCK_STREAM)
s2.connect(('localhost',8888))

while True:

    req = input('input number(1,2, quit): ')

    if req == '1':
        s = s1
    elif req == '2':
       s = s2
        
    elif req == 'quit':
        s1.send(b'quit')
        s2.send(b'quit')
        s1.close()
        s2.close()
        break
    
    else:
        continue
        print('다시 입력하세요')
    
    s.send('Request'.encode())
    msg = s.recv(BUF_SIZE)

    if not msg:
        s.close()
    else :
        rx_size = len(msg)
        data = msg
        while rx_size < LENGTH:
            msg = s.recv(BUF_SIZE)
            if not msg:
                s.close()
                sys.exit()
            data = data + msg
            rx_size += len(msg)

        if rx_size < LENGTH:
            s.close()
            sys.exit()
        size = int(data)
        print('server:', size)

    s.send('OK'.encode())
    rx_size = 0
    f = open('devicedata.txt' , 'ab')
    while rx_size < size:
        data = s.recv(BUF_SIZE)
        if not data:
            break
        f.write(data)
        f.write(b'\n')
        rx_size +=len(data)

    if rx_size < size:
        s.close()
        sys.exit()
    print("complete")
    f.close()
 
