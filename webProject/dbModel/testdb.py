from django.http import HttpResponse
from dbModel.models import Syscall
import datetime

def testdb(request):
    # test1 = Syscall.objects.insert()
    b = Syscall(host_id=2,host_name="test1",ip_addr="192.168.1.1",syscall_id=12,syscall_name="test",re_sys_addr="xs0xsa",now_sys_addr="xs0xsa",is_edit=0,time=datetime.datetime.now())
    b.save()
    # data = Syscall.objects.filter("host_id")
    # Syscall(host_id=2, host_name="test1", ip_addr="192.168.1.1", syscall_id=12, syscall_name="test",
    #         re_sys_addr="xs0xsa", now_sys_addr="xs0xsa", is_edit=0, time=datetime.datetime.now()).save()
    datas = Syscall.objects.all()[:5]
    vars = ""
    for var in datas:
        vars += str(var.ip_addr) + ";"
    data = vars
    print(data)
    return HttpResponse("<p>" + str(data) + "</p>")