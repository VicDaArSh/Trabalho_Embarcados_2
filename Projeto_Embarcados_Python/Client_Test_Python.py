import socket
import time

HOST = '127.0.0.1'  # The server's hostname or IP address
PORT = 1234        # The port used by the server

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))
    i = 1
    while True:
        if (i % 2) == 0:
            msg = 'P ' + str(i) + ' \n'
            s.sendall(msg.encode())
            print('Enviando ' + msg)
        else:
            msg = 'V ' + str(i) + ' \n'
            s.sendall(msg.encode())
            print('Enviando ' + msg)
        i = i+1
        time.sleep(0.3)
        if i == 1000:
            i = 1
        #data = s.recv(1024)
        #print('Received', repr(data))

