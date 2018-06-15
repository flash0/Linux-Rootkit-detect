import socket
import json

#客户端socket连接
def client_socket_conn():
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    # 建立连接:
    s.connect(('127.0.0.1', 9999))
    return s

def close_conn(s):
    s.close()

def sent(conn,data):
    conn.send(data)

def recv(conn):
    result = conn.recv(1024).decode('utf-8')
    return result

def load_data(data):
    return json.loads(data)


def dump_data(data):
    return json.dumps(data)