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

conn, addr = sock.accept()
msg = conn.recv(BUF_SIZE)
print('client:', addr, msg.decode())

if not msg:
    conn.close()
    

elif msg == b'Register':
    while True:
        temp = random.randint(0, 40)
        hum = random.randint(0, 100)
        light = random.randint(70, 150)
        now = time.strftime('%c', time.localtime(time.time()))

        data = now + ': ' + 'Device1: '+'Temp='+ str(temp) + ', Humid=' + str(hum) + ', lilum=' + str(light)
        conn.send(data.encode())

        time.sleep(3)
                
    
else:
    print('client:', addr, msg.decode())
    conn.close()
    
