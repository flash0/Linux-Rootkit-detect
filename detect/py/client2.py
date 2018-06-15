#! /usr/bin/env python
# _*_ coding: utf-8 _*_

# from . import client_data
# from . import translate

import socket
import json
import time
import client_data
import translate
import sys
import os
from ctypes import *

def main():
    
    host_name = socket.gethostname()
    host_id = client_data.get_host_id()
    flag = 1
    while flag:
        try:
            s = translate.client_socket_conn()
            flag = 0
        except:
            print("连接服务器失败，请检查网络！")
            print("10秒后尝试重连......")
            time.sleep(2)
    while True:
	detect()
        syscall_data = client_data.get_syscall_data(host_id,host_name)
        send_data1 = translate.dump_data(syscall_data)
	translate.sent(s,bytes(send_data1))
	#translate.sent(s,bytes(send_data,'utf-8'))
	proc_data = client_data.get_proc_data(host_id,host_name)
	send_data2 = translate.dump_data(proc_data)
	translate.sent(s,bytes(send_data2))
	file_data = client_data.get_file_data(host_id,host_name)
	send_data3 = translate.dump_data(file_data)
	translate.sent(s,bytes(send_data3))
        #print(syscall_data)
        time.sleep(3600)

def detect():
    libs = cdll.LoadLibrary(os.getcwd()+'/syscall.so')
    libs.main()
if __name__ == '__main__':
    main()
