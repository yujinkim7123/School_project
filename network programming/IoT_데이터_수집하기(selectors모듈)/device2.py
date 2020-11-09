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

conn, addr = sock.accept()
msg = conn.recv(BUF_SIZE)
print('client:', addr, msg.decode())

if not msg:
    conn.close()
    
elif msg == b'Register':
    while True:
        heart = random.randint(40, 140)
        steps = random.randint(2000, 6000)
        cal = random.randint(1000, 4000)
        now = time.strftime('%c', time.localtime(time.time()))

        data = now + ': ' + 'Device2: '+'Heartbeat='+ str(heart) + ', Steps=' + str(steps) + ', Cal=' + str(cal)
        conn.send(data.encode())
        
        time.sleep(5)
        
else:
    print('client:', addr, msg.decode())
    conn.close()
    
