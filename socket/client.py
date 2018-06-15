#! /usr/bin/env python
# _*_ coding: utf-8 _*_

'test demo'

__author__ = 'DarrenW'

import socket
import json
import time

def main():
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    # 建立连接:
    s.connect(('127.0.0.1', 9999))
    # 接收欢迎消息:
    print(s.recv(1024).decode('utf-8'))
    for data in [b'Michael', b'Tracy', b'Sarah']:
        # 发送数据:
        s.send(data)
        print(s.recv(1024).decode('utf-8'))
    a = {1:"1"}
    b = json.dumps(a)
    c = bytes(b,'utf-8')
    print(type(c))
    s.send(c)
    s.send(b'exit')
    time.sleep(2)
    s.close()

if __name__ == '__main__':
    main()
