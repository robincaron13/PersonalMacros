import socket

def ServerProgram():
    host = socket.gethostname()
    port = 5000
    ServerSocket = socket.socket()
    ServerSocket.bind((host, port))
    ServerSocket.listen(2)
    conn, ClientAddress = ServerSocket.accept()
    print("Connection from: " + str(ClientAddress))
    while True:
        ClientMsg = conn.recv(1024).decode()
        if not ClientMsg:
            break
        print("from connected user: " + str(ClientMsg))
        ClientMsg = input(' -> ')
        conn.send(ClientMsg.encode())
    conn.close()
if __name__ == '__main__':
    ServerProgram()

def ClientProgram():
    host = socket.gethostname()
    port = 5000 ## We fixed here.
    ClientSocket = socket.socket()
    ClientSocket.connect((host, port))
    ClientMessage = input(" -> ")
    while ClientMessage.lower().strip() != 'bye':
        ClientSocket.send(ClientMessage.encode())
        ServerMsg = ClientSocket.recv(1024).decode()
        print('Received from server: ' + ServerMsg)
        ClientMessage = input(" -> ")
    ClientSocket.close()
if __name__ == '__main__':
    ClientProgram()


