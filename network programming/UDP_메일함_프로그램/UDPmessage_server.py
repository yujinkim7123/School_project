from socket import *

port = 5555
BUFF_SIZE = 1024

s_sock = socket(AF_INET, SOCK_DGRAM)
s_sock.bind(('',port))

mboxID = dict()
listnumber = 0
mlist =[]

while True:
    data, addr = s_sock.recvfrom(BUFF_SIZE)

    datamsg = data.decode()
    
    if not data:
        print('not data')
        break
    
    elif datamsg == 'quit':
        break
    
    datalist = datamsg.split(maxsplit=2)

    if datalist[0] == 'send':
        
        if datalist[1] in mboxID:
           key = mboxID[datalist[1]]
           mlist[key].append(datalist[2])
            
        else:
            mboxID[datalist[1]] = listnumber
            mlist.append([])
            mlist[listnumber].append(datalist[2])
            listnumber = listnumber + 1
            
        s_sock.sendto('OK'.encode(), addr)

    elif datalist[0] == 'receive':
        
        if datalist[1] in mboxID:

           key = mboxID[datalist[1]]
           
           if len(mlist[key]) < 1:
               s_sock.sendto("No messages".encode(),addr)
               
           else:
               msg = mlist[key][0]
               del(mlist[key][0])
               s_sock.sendto(msg.encode(),addr)

        else:
           s_sock.sendto("No messages".encode(),addr)
           
    else:
        print('worng messages format')

    

    
           
           
           
        
        
            
        
