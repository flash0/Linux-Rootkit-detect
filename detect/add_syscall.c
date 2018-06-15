#include "common.h"
#include "check_process.h"
#include "check_files.h"
#include "check_syscalls.h"

asmlinkage long sys_mycall(long num);
unsigned long orig_cr0;
//unsigned 
static int (*anything_saved)(void);

static inline void protect_memory(void)
{	
    
    write_cr0(orig_cr0);
}

static inline void unprotect_memory(void)
{
    write_cr0(orig_cr0 & ~0x00010000);
}

void **find_syscall_table(void)
{
    void **syscall_table;
    void *i = (void*)START_ADDRESS;
    while(i<END_ADDRESS)
    {
	syscall_table = (void **) i;
	if(syscall_table[__NR_close] == (void *)sys_close)
	{
	    return syscall_table;
	}
	i += sizeof(void *);
    }
}

asmlinkage long sys_mycall(long num)
{
    printk(KERN_INFO"this is my_syscall!\n");
    
    check_process();
    check_files();
    check_syscalls();
    return 1;
}

int add_syscall_init(void)
{
    printk(KERN_INFO"moudle init1");
    orig_cr0 = read_cr0();
    printk(KERN_INFO"moudle init2");
    void **syscall_table;
    syscall_table = find_syscall_table();
    printk(KERN_INFO"moudle init3");
    anything_saved = (int(*)(void))(syscall_table[my_syscall_num]);//save ori address
    printk(KERN_INFO"moudle init4");
    unprotect_memory();
    printk(KERN_INFO"moudle init5");
    syscall_table[my_syscall_num] = (unsigned long)&sys_mycall;
    printk(KERN_INFO"moudle init6");
    protect_memory();
    printk(KERN_INFO"moudle init7");
    return 1;
}

void add_syscall_exit(void)
{
    void **syscall_table;
    syscall_table = find_syscall_table();
    unprotect_memory();
    syscall_table[my_syscall_num] = (unsigned long)&anything_saved;
    protect_memory();
    printk(KERN_INFO"moudle exit");
}

