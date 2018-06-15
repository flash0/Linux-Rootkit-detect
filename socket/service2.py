#! /usr/bin/env python
# _*_ coding: utf-8 _*_

'test demo'

__author__ = 'DarrenW'

import socket
import threading
import time
import json
import sqlite3
import data_sql

def main():
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.bind(('0.0.0.0', 9999))
    s.listen(5)
    print('Waiting for connection...')
    db_conn = data_sql.get_conn()
    while True:
        # 接受一个新连接:
        sock, addr = s.accept()
        # 创建新线程来处理TCP连接:
        t = threading.Thread(target=tcplink, args=(sock, addr,db_conn))
        t.start()

def tcplink(sock, addr,db_conn):
    print('Accept new connection from %s:%s...' % addr)
    all_data = bytes()

    while True:
        data = sock.recv(1024)
        # time.sleep(1)
        if not data or data.decode('utf-8') == 'exit':
            break

        if data.decode('utf-8') != 'end':
            print(data)
            all_data += data
        else:
            # print(all_data)
            b = json.loads(all_data)
            print(type(b))
            b = data_add_ip(b, addr)
            insert_db(db_conn, b)
            all_data = bytes()

        # try:
        #     b = json.loads(data)
        #     b = data_add_ip(b,addr)
        #     insert_db(db_conn,b)
        # except:
        #     print("json load  error!")
        #     b = data.decode('utf-8')
        #     print(b)
    sock.close()
    print('Connection from %s:%s closed.' % addr)

def insert_db(db_conn,datas):
    types = datas['type']
    recv_time = datas['time']
    data = datas['data']
    # print(data)
    if types == 'syscall':
        for key,value in data.items():
            data_sql.insert_syscall(db_conn,value,recv_time)
    elif types == "proc":
        for key,value in data.items():
            data_sql.insert_proc(db_conn,value,recv_time)
    elif types == "file":
        for key,value in data.items():
            data_sql.insert_file(db_conn,value,recv_time)


#处理数据，加入IP地址
def data_add_ip(recv_data,addr):
    type = recv_data['type']
    data = recv_data['data']
    recv_time = recv_data['time']
    result = {}
    for i in data.keys():
        data[i]['ip_addr'] = addr[0]
    result['type'] = type
    result['data'] = data
    result['time'] = recv_time

    return result


if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        print("close server")
