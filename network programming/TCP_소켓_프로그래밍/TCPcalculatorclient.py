import socket
address = ("localhost", 2500)
BUFSIZE = 1024
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(address)


while True:
    msg = input("Message to send: ")
    try:
        bytesSent = s.send(msg.encode())
    except:
        print('connection closed')
        break

    try:
        data = s.recv(BUFSIZE)
    except:
        print('connection closed')
        break
    else:
        if not data:
            break
        print('Received message:', data.decode())

s.close()
