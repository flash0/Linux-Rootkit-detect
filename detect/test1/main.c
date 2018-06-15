#include <linux/string.h>
// #include <linux/sched.h>
#include<linux/init.h>
#include "common.h"
#include "check_process.h"
#include "check_files.h"
static int test_init(void)
{
    printk(KERN_ALERT "hello test module start!\n");
    check_process();
    check_files();
    return 0;
}



static void test_exit(void)
{
    printk(KERN_ALERT "good bye test moudle\n");
}


MODULE_LICENSE("GPL"); 
module_init(test_init);
module_exit(test_exit);
//MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("li chen yong");
MODULE_DESCRIPTION("This is a simple example!/n");
MODULE_ALIAS("A simplest example");
