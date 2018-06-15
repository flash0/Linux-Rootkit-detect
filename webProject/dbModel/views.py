from django.shortcuts import render
from django.http import HttpResponse
from dbModel.models import *
# Create your views here.
def test2(test):
    return HttpResponse("Hello World, Django")

def test3(test):
    return HttpResponse("Hello World, Django3333")


def home(request):
    return render(request,'index.html')

def proc(request):
    datas = Proc.objects.all()
    for data in datas:
        print(data.host_id)

    return render(request,'pages/table/proc.html',{'datas':datas})


def syscall(request):
    datas = Syscall.objects.all()
    for data in datas:
        print(data.host_id)
    # return HttpResponse("Hello World, Django3333")
    return render(request,'pages/table/syscall.html',{'datas':datas})

def file(request):
    datas = File.objects.all()
    for data in datas:
        print(data.host_id)
    return render(request,'pages/table/file.html',{'datas':datas})
