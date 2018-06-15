#! /usr/bin/env python
# _*_ coding: utf-8 _*_

'test demo'

__author__ = 'DarrenW'

import socket
import threading
import time
import json
# import sqlite3

def main():
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.bind(('127.0.0.1', 9999))
    s.listen(5)
    print('Waiting for connection...')
    while True:
        # 接受一个新连接:
        sock, addr = s.accept()
        # 创建新线程来处理TCP连接:
        t = threading.Thread(target=tcplink, args=(sock, addr))
        t.start()

def tcplink(sock, addr):
    print('Accept new connection from %s:%s...' % addr)
    sock.send(b'Welcome!')
    while True:
        data = sock.recv(1024)
        time.sleep(1)
        if not data or data.decode('utf-8') == 'exit':
            break

        sock.send(('Hello, %s!' % data.decode('utf-8')).encode('utf-8'))
        try:
            b = json.loads(data)
            print(b)
            print(type(b))
        except:
            print("load error!")
            b = data.decode('utf-8')
            print(b)
    sock.close()
    print('Connection from %s:%s closed.' % addr)


def insert_db(conn,data):
    print()

def test_in():
    a = ["1","2","3"]
    b = "2"
    if b in a:
        print("in")
    else:
        print("not in")


if __name__ == '__main__':
    try:
        # main()
        test_in()
    except KeyboardInterrupt:

        print("close server")
