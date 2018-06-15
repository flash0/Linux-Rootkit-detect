import sqlite3

def get_conn():
    conn = sqlite3.connect("../webProject/db.sqlite3",check_same_thread=False)
    return conn

def insert_syscall(conn,data={},recv_time=''):
    sql = '''insert into dbModel_syscall(host_id,host_name,ip_addr,syscall_id,syscall_name,re_sys_addr,now_sys_addr, is_edit,time) 
            values(%d,'%s','%s',%d,'%s','%s','%s',%d,'%s') '''%(int(data['host_id']),data['host_name'],data['ip_addr'],int(data['syscall_id']),
                                                    data['syscall_name'],data['re_sys_addr'],data['now_sys_addr'], int(data['is_edit']),recv_time)
    print(sql)
    cursor = conn.cursor()
    cursor.execute(sql)
    conn.commit()

def insert_proc(conn,data={},recv_time=''):
    sql = '''insert into dbModel_proc(host_id,host_name,ip_addr,proc_id,proc_name,is_hide,time) 
            values(%d,'%s','%s','%s','%s',%d,'%s') ''' % (int(data['host_id']), data['host_name'], data['ip_addr'],
                                                data['proc_id'], data['proc_name'],int(data['is_hide']),recv_time)
    print(sql)
    cursor = conn.cursor()
    cursor.execute(sql)
    conn.commit()


def insert_file(conn,data={},recv_time=''):
    sql = '''insert into dbModel_file(host_id,host_name,ip_addr,file_name,file_type,is_hide,time) 
             values(%d,'%s','%s','%s','%s',%d,'%s')''' % (int(data['host_id']), data['host_name'], data['ip_addr'],
                                                data['file_name'], data['file_type'],int(data['is_hide']), recv_time)
    # conn = get_conn()
    print(sql)
    cursor = conn.cursor()
    cursor.execute(sql)
    conn.commit()

if __name__ == "__main__":
    import datetime
    conn = get_conn()
    cursor = conn.cursor()
    now  = datetime.datetime.now()
    syscall_data = {
        "host_id" : 1, "host_name":"ubuntu1", "ip_addr":"192.168.1.221", "syscall_id":223, "syscall_name":"sys_test","re_sys_addr":"1011",  "now_sys_addr":"1011", "is_edit":0, "time":str(now)
    }

    proc_data = {
        "host_id" : 1, "host_name":"ubuntu1", "ip_addr":"192.168.1.221", "proc_id":22, "proc_name":"sys_test","is_hide":0, "time":str(now)
    }

    file_data = {
        "host_id": 1, "host_name": "ubuntu1", "ip_addr": "192.168.1.221", "file_name": "test.txt", "file_type": "txt", "is_hide": 0, "time":str(now)
    }


    print(syscall_data)
    # insert_syscall(conn,syscall_data)
    # insert_proc(conn,proc_data)
    insert_file(conn,file_data)

    conn.close()