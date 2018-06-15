#include "common.h"


/*
 * Function used for local logging.
 */
void
write_to_file(struct file *fd, char *buf, long len)
{
	loff_t off = 0;
	mm_segment_t old_fs;

	if (!IS_ERR (fd)) {
		old_fs = get_fs();
		set_fs(get_ds());

		vfs_write(fd, buf, len, &off);

		set_fs(old_fs);
	} else {
		printk("%s\n", buf);
	}
}


