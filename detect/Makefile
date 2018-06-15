obj-m   := check.o
check-y	:= main.o add_syscall.o common.o check_process.o check_files.o check_syscalls.o


KDIR    := /lib/modules/$(shell uname -r)/build
PWD     := $(shell pwd)

default:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
