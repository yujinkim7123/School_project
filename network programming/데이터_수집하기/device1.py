from socket import *
import os
import random
import time

BUF_SIZE = 1024
LENGTH = 10

sock = socket(AF_INET, SOCK_STREAM)
sock.bind(('',7777))
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
            temp = random.randint(0, 40)
            hum = random.randint(0, 100)
            light = random.randint(70, 150)
            now = time.strftime('%c', time.localtime(time.time()))

            data = now + ': ' + 'Device1: '+'Temp='+ str(temp) + ', Humid=' + str(hum) + ', lilum=' + str(light)

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
