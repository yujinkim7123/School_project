from socket import *

def sum1(a,b):
    return a+b

def sub1(a,b):
    return a-b

def mul1(a,b):
    return a*b

def div1(a,b):
    return a/b


fun = { '+': sum1 , '-':sub1, '*': mul1, '/': div1}


port = 2500
BUFSIZE = 1024

sock = socket(AF_INET, SOCK_STREAM)
sock.bind(('', port))
sock.listen(1)

conn, (remotehost, remoteport) = sock.accept()

while True:
    try:
        data = conn.recv(BUFSIZE)
    except:
        break
    else:
        data = data.decode()
        if not data:
            break
        if data == 'q':
            break
        s = data.split()
        re = round(fun[s[0]](float(s[1]),float(s[2])), 1)
        re = str(re)
        conn.send(re.encode())
        
conn.close() 
                
