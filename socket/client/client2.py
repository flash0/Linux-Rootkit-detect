#! /usr/bin/env python
# _*_ coding: utf-8 _*_

'test demo'

__author__ = 'DarrenW'

# from . import client_data
# from . import translate

import socket
import json
import time
import client_data
import translate
import sys



# def main1():
#     host_name = socket.gethostname()
#     host_id = client_data.get_host_id()
#     s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
#     # 建立连接:
#     s.connect(('127.0.0.1', 9999))
#     # 接收欢迎消息:
#     print(s.recv(1024).decode('utf-8'))
#     for data in [b'Michael', b'Tracy', b'Sarah']:
#         # 发送数据:
#         s.send(data)
#         print(s.recv(1024).decode('utf-8'))
#     a = {1:"1"}
#     b = json.dumps(a)
#     c = bytes(b,'utf-8')
#     print(type(c))
#     s.send(c)
#     s.send(b'exit')
#     time.sleep(2)
#     s.close()


def main():
    host_name = socket.gethostname()
    host_id = client_data.get_host_id()
    flag = 1
    while flag:
        try:
            s = translate.client_socket_conn()
            flag = 0
        except:
            print("连接服务器失败，请检查网络！\n")
            sys.exit(0)
    while True:
        syscall_data = client_data.get_syscall_data(host_id,host_name)
        send_data = translate.dump_data(syscall_data)
        translate.sent(s,bytes(send_data,'utf-8'))
        print(syscall_data)
        time.sleep(10)

if __name__ == '__main__':
    main()
