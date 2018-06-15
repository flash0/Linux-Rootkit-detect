#include "check_files.h"

int check_files(void)
{
  struct list_head* plist;
  struct file *fd;
  struct file *fi;
  char log_path[128] = "/files.log";
  char dir_path[128] = "/home/lcy/test2/";
  char message[128];
  fd = filp_open(log_path, O_CREAT|O_WRONLY|O_APPEND|O_TRUNC, S_IRWXU);
//  void *ret;
  printk(KERN_INFO"start files scan");
  
  if((fi = filp_open(dir_path,O_RDONLY,0)) == NULL)
  {
    printk(KERN_INFO"open file error!\n");
    return -1;
  }
  if(IS_ERR(fi)){
    printk(KERN_INFO"not dir!\n");
    return -1;
  }

  list_for_each(plist,&(fi->f_path.dentry->d_subdirs))
  {
    struct dentry* temp=list_entry(plist,struct dentry,d_child);
    if(temp)
    if(temp->d_inode)
    if(d_count(temp))
    {
      printk(KERN_INFO"find dir : %s!\n",temp->d_name.name);
      memset(message, 0, 128);
      sprintf(message, "dirs %s\n", temp->d_name.name);
      write_to_file(fd,message, strlen(message));
    }else{
      printk(KERN_INFO"find file : %s!\n",temp->d_name.name);
      memset(message, 0, 128);
      sprintf(message, "file %s\n", temp->d_name.name);
      write_to_file(fd,message, strlen(message));
    }
  }
  return 1;
}
