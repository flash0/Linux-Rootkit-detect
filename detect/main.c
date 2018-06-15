#include <linux/string.h>
// #include <linux/sched.h>
#include<linux/init.h>
#include "common.h"

MODULE_LICENSE("Dual BSD/GPL");
static int test_init(void)
{ 
    printk(KERN_ALERT "hello test module start!\n");        
    if(add_syscall_init() !=1)
    {
	printk(KERN_ALERT "add syscall error!\n");
	return 0;
    }
    return 0;
}



static void test_exit(void)
{
    add_syscall_exit();
    printk(KERN_ALERT "good bye test moudle\n");
}


//MODULE_LICENSE("GPL"); 
module_init(test_init);
module_exit(test_exit);
MODULE_AUTHOR("li chen yong");
MODULE_DESCRIPTION("This is a simple example!/n");
MODULE_ALIAS("A simplest example");
