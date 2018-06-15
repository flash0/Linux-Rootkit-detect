# _*_ coding: utf-8 _*_
import socket
import json
import time
#客户端socket连接
def client_socket_conn():
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    # 建立连接:
    s.connect(('192.168.174.1', 9999))
    return s

def close_conn(s):
    s.close()

def sent(conn,data):
    legth = len(data)
    header={}
    send_len = 1024
    count = int(legth/send_len)+1
    for i in range(0,count):
        #print(data[i*send_len:(i+1)*send_len])
        conn.sendall(data[i*send_len:(i+1)*send_len])
    time.sleep(5)
    conn.sendall(b'end')    
    #conn.sendall(b'exit')    

def recv(conn):
    result = conn.recv(1024).decode('utf-8')
    return result

def load_data(data):
    return json.loads(data)


def dump_data(data):
    return json.dumps(data)
