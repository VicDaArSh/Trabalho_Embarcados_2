import socket

print('teste')
HOST = '192.168.137.1'  # Standard loopback interface address (localhost)
PORT = 1234        # Port to listen on (non-privileged ports are > 1023)

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST, PORT))
    print('listening...')
    s.listen()
    conn, addr = s.accept()
    print('Conectado')
    with conn:
        print('Connected by', addr)
        while True:
            data = conn.recv(1024).decode()
            print('data: ' + data)
            if not data:
                break
            #conn.sendall(b'received')