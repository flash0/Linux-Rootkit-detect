import os
import sys
import time
import socket
import json
import datetime

#生成syscall的检测数据
def get_syscall_data(host_id='',host_name=''):
    data = {}
    datas = {}
    i = 1
    with open('syscall.log', 'r') as syscall_file:
        while True:
            lines = syscall_file.readline()
            if not lines:
                break
            data2 = lines.split()
            data['host_id'] = host_id
            data['host_name'] = host_name
            try:
                data['syscall_name'] = data2[0]
                data['syscall_id'] = data2[1]
                data['re_sys_addr'] = data2[2]
                data['now_sys_addr'] = data2[3]
            except:
                pass
            if data['re_sys_addr'] == data['now_sys_addr']:
                data['is_edit'] = 0
            else:
                data['is_edit'] = 1
            datas[i] = data
            i += 1
    result = {}
    result['type'] = "syscall"
    result['data'] = datas
    result['time'] = str(datetime.datetime.now())
    return result


def get_host_id():
    with open("config.json","r") as f:
        data = json.load(f)
    if 'host_id' in data:
        host_id = data['host_id']
    else:
        host_id = 0
    return host_id

def get_file_data(host_id='',host_name=''):
    print()



def  set_syscall_data(data,host_id,host_name):
    result = {}
    k = 0
    for i in data:
        result[k]['host_id'] = host_id
        result[k]['host_name'] = host_name
        result[k]['ip_addr'] = ''
        result[k]['syscall_id'] = ''
        result[k]['syscall_name'] = ''
        result[k]['re_sys_addr'] = ''
        result[k]['now_sys_addr'] = ''
        if result[k]['re_sys_addr'] == result[k]['now_sys_addr']:
            result[k]['is_edit'] = 0
        else:
            result[k]['is_edit'] = 1
        result[k]['time'] = ''
        k += 1

    return result


#user_data  用户层数据
#kernel_data 内核数据
def set_proc_data(user_data, kernel_data,host_id, host_name):
    result = {}
    k = 0
    for i in kernel_data:
        result[k]['host_id'] = host_id
        result[k]['host_name'] = host_name
        result[k]['ip_addr'] = ''
        result[k]['proc_id'] = ''
        result[k]['proc_name'] = ''
        if result[k]['proc_id']:            #in array
            result[k]['is_hide'] = 0
        else:
            result[k]['is_hide'] = 1
        result[k]['time'] = ''
        k += 1

    return result


#user_data  用户层数据
#kernel_data 内核数据
def set_file_data(user_data, kernel_data,host_id, host_name):
    result = {}
    k = 0
    for i in kernel_data:
        result[k]['host_id'] = host_id
        result[k]['host_name'] = host_name
        result[k]['ip_addr'] = ''
        result[k]['file_name'] = ''
        result[k]['file_type'] = ''
        if result[k]['proc_id']:            #in array
            result[k]['is_hide'] = 0
        else:
            result[k]['is_hide'] = 1
        result[k]['time'] = ''
        k += 1
    return result

if __name__ == "__main__":
    print(get_host_id())


