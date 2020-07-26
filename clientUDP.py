import socket

cs = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
address = ("127.0.0.1", 542)
message = str.encode("CSCI 379 Lybryant Wright's UDP Socket Works")
cs.sendto(message, address)
