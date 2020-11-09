from socket import *
import os
import random
import time

BUF_SIZE = 1024
LENGTH = 10

sock = socket(AF_INET, SOCK_STREAM)
sock.bind(('',8888))
sock.listen(10)
print('File server is running...')

while True:
    conn, addr = sock.accept()
    
    while True:
        msg = conn.recv(BUF_SIZE)
        if not msg:
            conn.close()
            break
        elif msg == b'Request':        
            heart = random.randint(40, 140)
            steps = random.randint(2000, 6000)
            cal = random.randint(1000, 4000)
            now = time.strftime('%c', time.localtime(time.time()))

            data = now + ': ' + 'Device2: '+'Heartbeat='+ str(heart) + ', Steps=' + str(steps) + ', Cal=' + str(cal)

            size = len(data)
            conn.send(str(size).zfill(LENGTH).encode())
            msg = conn.recv(BUF_SIZE) 
            if not msg:
                conn.close()
                break
            elif msg == b'OK':
                conn.send(data.encode())
            else:
                print('client:', addr, msg.decode())
                conn.close()
                
        elif msg == 'quit':
            conn.close()
            print('client:', addr, msg.decode())
            break
        
        else:
            print('client:', addr, msg.decode())
            conn.close()
            break
