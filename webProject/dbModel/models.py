from django.db import models

# Create your models here.
class Syscall(models.Model):
    # people = models.Manager()
    id = models.AutoField(primary_key=True)
    host_id = models.IntegerField(max_length=10,null=True)
    host_name = models.CharField(max_length=30,null=True)
    ip_addr = models.CharField(max_length=16,null=True)
    syscall_id = models.IntegerField(max_length=10,null=True)
    syscall_name = models.CharField(max_length=30,null=True)
    re_sys_addr = models.CharField(max_length=30,null=True)
    now_sys_addr = models.CharField(max_length=30,null=True)
    is_edit = models.IntegerField(max_length=1,default=0)
    time = models.DateTimeField(null=True)




class Proc(models.Model):
    id = models.AutoField(primary_key=True)
    host_id = models.IntegerField(max_length=10, null=True)
    host_name = models.CharField(max_length=30, null=True)
    ip_addr = models.CharField(max_length=16, null=True)
    proc_id = models.CharField(max_length=20, null=True)
    proc_name = models.CharField(max_length=50,null=True)
    is_hide = models.IntegerField(max_length=1,default=0,null=True)
    time = models.DateTimeField(null=True)


class File(models.Model):
    id = models.AutoField(primary_key=True)
    host_id = models.IntegerField(max_length=10, null=True)
    host_name = models.CharField(max_length=30, null=True)
    ip_addr = models.CharField(max_length=16, null=True)
    file_name = models.CharField(max_length=50, null=True)
    file_type = models.CharField(max_length=10,default="file")
    is_hide = models.IntegerField(max_length=1,default=0)
    time = models.DateTimeField(null=True)
