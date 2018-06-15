#include <linux/module.h>
#include<linux/kernel.h>
#include <linux/sched.h>
#include <linux/fs.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/uaccess.h>

void write_to_file(struct file *fd, char *buf, long len);

