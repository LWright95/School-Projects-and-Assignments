import socket

port = 542
server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server.bind(('', port))
while True:  
    data,newClient = server.recvfrom(1024)
    print("New Client Connected: ", newClient)
    print("Data Received: ", data)
    print("Converting message to UPPERCASE...")
    upperMsg = data.upper()
    print("New Message: ",upperMsg)
    server.close()
    
    