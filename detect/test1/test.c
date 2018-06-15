#include <linux/string.h>
#include<linux/init.h>
#include<linux/kernel.h>

#include "common.h"


void tasks(void)
{
  struct task_struct *taskp;
  // struct  fdtable *pfdt;
  // int i;
  printk("pid  pPid  name\tpname\n");
  for_each_process(taskp){
      task_lock(taskp);
      if (taskp && taskp->mm && taskp->mm->exe_file && taskp->mm->exe_file->f_path) // && (task->mm->exe_file->f_path))
    // printk(KERN_ALERT "%d %d  %s\t%s\n",taskp->pid,taskp->parent->pid,taskp->comm,taskp->parent->comm);
    {
      printk("%d\t%s\n", taskp->pid,taskp->mm->exe_file->f_path);
    }
    task_uplock(taskp);
  }

}

void callUser(void)
{
  int result = 0;
  char cmdPath[] = "/bin/bash";
  char* cmdArgv[]={cmdPath, "-c", "/bin/ls >> /tmp/list", NULL};
}


static int test_init(void)
{
    printk(KERN_ALERT "hello test module start!\n");
    tasks();
    return 0;
}


static void test_exit(void)
{
    printk(KERN_ALERT "good bye test moudle\n");
}


module_init(test_init);
module_exit(test_exit);
MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("li chen yong");
MODULE_DESCRIPTION("This is a simple example!/n");
MODULE_ALIAS("A simplest example");
