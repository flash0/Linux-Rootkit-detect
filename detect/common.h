#include <linux/module.h>
#include<linux/kernel.h>
#include <linux/sched.h>
#include <linux/fs.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/uaccess.h>
#include <linux/delay.h>
#include <asm/uaccess.h>
#include <linux/syscalls.h>
#include <linux/version.h>


#if defined __i386__
    #define START_ADDRESS 0xc0000000
    #define END_ADDRESS 0xd0000000
#elif defined __x86_64__
    #define START_ADDRESS 0xffffffff81000000
    #define END_ADDRESS 0xffffffffa2000000
#else
    #error ARCH_ERROR_MESSAGE
#endif
#define my_syscall_num 366
void write_to_file(struct file *fd, char *buf, long len);

int add_syscall_init(void);
void add_syscall_exit(void);
