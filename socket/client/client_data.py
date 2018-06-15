import json
import datetime
import subprocess


def get_ls_list():
    result = []
    i = 0
    ls_out = subprocess.Popen(['ls -a'], shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    ls_out.wait()
    out = ls_out.stdout
    for line in out.readlines():
        line = line.strip('\n')
        if line != '' and line != '.' and line != "..":
            result.append(line)
    return result


def get_ps_list():
    result = []
    # proc = {}
    i = 0
    ls_out = subprocess.Popen(['ps -A'], shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    ls_out.wait()
    out = ls_out.stdout
    for line in out.readlines():
        proc = {}
        lines = line.strip('\n')
        lines = line.split()
        if line != '' and i >= 1:
            # proc['proc_id'] = lines[0]
            # proc['proc_name'] = lines[3]
            result.append(lines[0])
        i += 1
    return result


# a = get_ps_list()
# print(a)


def get_proc_data(host_id='', host_name=''):
    user_proc_list = get_ps_list()
    # print(user_proc_list)
    data = {}
    datas = {}
    i = 1
    with open('/process.log', 'r') as syscall_file:
        while True:
            lines = syscall_file.readline()
            if not lines:
                break
            data2 = lines.split()
            data = {}
            data['host_id'] = host_id
            data['host_name'] = host_name
            try:
                data['proc_id'] = data2[0]
                data['proc_name'] = data2[1]
            except:
                pass

            # check if the kernel pid in user pid
            if data['proc_id'] in user_proc_list:
                data['is_hide'] = 0
            else:
                data['is_hide'] = 1
            datas[i] = data
            i += 1
    result = {}
    result['type'] = "proc"
    result['data'] = datas
    result['time'] = str(datetime.datetime.now())
    return result


def get_file_data(host_id='', host_name=''):
    user_file_list = get_ls_list()
    # print(user_proc_list)
    data = {}
    datas = {}
    i = 1
    with open('/files.log', 'r') as syscall_file:
        while True:
            lines = syscall_file.readline()
            if not lines:
                break
            data2 = lines.split()
            data = {}
            data['host_id'] = host_id
            data['host_name'] = host_name
            try:
                data['file_type'] = data2[0]
                data['file_name'] = data2[1]
            except:
                pass

            # check if the kernel pid in user pid
            if data['file_name'] in user_file_list:
                data['is_hide'] = 0
            else:
                data['is_hide'] = 1
            datas[i] = data
            i += 1
    result = {}
    result['type'] = "file"
    result['data'] = datas
    result['time'] = str(datetime.datetime.now())
    return result


def get_syscall_data(host_id='', host_name=''):
    datas = {}
    i = 1
    with open('syscall.log', 'r') as syscall_file:
        while True:
            lines = syscall_file.readline()
            if not lines:
                break
            data2 = lines.split()
            data = {}
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


if __name__ == "__main__":
    print(get_host_id())


