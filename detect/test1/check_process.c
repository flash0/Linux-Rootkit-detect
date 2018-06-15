#include "check_process.h"
#include "common.h"


void check_process(void)
{
  struct task_struct *taskp;
  struct file *fd;
  char path[128] = "/process.log";
  char message[128];
  fd = filp_open(path, O_CREAT|O_WRONLY|O_APPEND|O_TRUNC, S_IRWXU);
  // struct  fdtable *pfdt;
  // int i;
  printk("pid  pPid  name\tpname\n");
  for_each_process(taskp){
      if (taskp )
    {
      memset(message, 0, 128);
      sprintf(message, "[%05d] %s\n", taskp->pid, taskp->comm);
      write_to_file(fd,message, strlen(message));
    }
  }

}

void callUser(void)
{
}
