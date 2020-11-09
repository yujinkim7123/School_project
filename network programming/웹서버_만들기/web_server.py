from socket import *

s = socket()
s.bind(('',80))
s.listen(10)

while True:
    c, addr = s.accept()

    data = c.recv(2024)
    msg = data.decode()
    req = msg.split('\r\n')
    req = req[0].split('/')
    req = req[1].split()
    filename = req[0]


    if filename == 'index.html':
        f = open(filename,'r', encoding='utf-8')
        data = f.read()
        mimeType = 'text/html'

    elif filename == 'iot.png':
        f = open(filename,'rb')
        data = f.read()
        mimeType = 'image/png'
            
    elif filename == 'favicon.ico':
        f = open(filename,'rb')
        data = f.read()
        mimeType = 'image/x-icon'

        
    else:
        c.send('HTTP/1.1 404 Not Found\r\n'.encode())
        c.send('\r\n'.encode())
        c.send('<HTML><HEAD><TITLE>Not Found</TITLE></HEAD>'.encode())
        c.send('<BODY>Not Found</BODY></HTML>'.encode())
        c.close()
        continue
    
    
    c.send('HTTP/1.1 200 OK\r\n'.encode())
    response = 'Content-Type: '+ mimeType + '\r\n'
    c.send(response.encode())
    c.send('\r\n'.encode())

    if filename == 'index.html':
        c.send(data.encode('euc-kr'))

    elif filename == 'iot.png':
        c.send(data)
            
    elif filename == 'favicon.ico':
        c.send(data)
        
    c.close()
