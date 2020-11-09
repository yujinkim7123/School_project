import asyncio
import time

port = 3333
BUFSIZE = 1024

clients = []

async def handle(reader, writer):
    
    addr = writer.get_extra_info('peername')
    
    if writer not in clients:
        print("new client", addr)
        clients.append(writer)
    
    
    while True:
        data = await reader.read(BUFSIZE)

        if not data:
            print(addr, 'exited')
            clients.remove(writer)
            writer.close()
            break
        
        if 'quit' in data.decode():
            print(addr, 'exited')
            clients.remove(writer)
            writer.close()
            break
        

        print(time.asctime() + str(addr) + ':' + data.decode())

        for client in clients:
            if client !=  writer:
                client.write(data)
                await client.drain()
        
async def main():
    
    server = await asyncio.start_server(handle, '', port)

    addr = server.sockets[0].getsockname()
    print(f'Serving on {addr}')
    
    await server.serve_forever()


asyncio.run(main())


        
