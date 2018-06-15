/******************************************************************************
 *
 * Name: check_syscalls.c 
 * 
 *
 *****************************************************************************/

 
#include "check_syscalls.h"

void **find_syscall_tables(void);
void **find_syscall_tables(void)
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


int
check_syscalls (void)
{
	int hooked_syscalls = 0;
	char message[128];
	struct file *fd;
	char log_path[128] = "/syscall.log";
	void **sys_call_table;	
	void **re_sys_call_table;	
	void **now_sys_call_table;

	
 	fd = filp_open(log_path, O_CREAT|O_WRONLY|O_APPEND|O_TRUNC, S_IRWXU);		
	
		
	now_sys_call_table = (void *) sysmap_sys_call_table;
	re_sys_call_table = sys_call_table = find_syscall_tables();
	
	
	/* log our current op */
	sprintf(message, "sys_call_table\t1000\t%x\t%x\n",re_sys_call_table,now_sys_call_table);
	write_to_file(fd,message, strlen(message));
	
	sprintf(message, "sys_open\t%d\t%x\t%x\n",__NR_open,(void *)sysmap_sys_read,(void *)sys_call_table[__NR_open]);
	write_to_file(fd,message, strlen(message));
	
	sprintf(message, "sys_read\t%d\t%x\t%x\n",__NR_read,(void *)sysmap_sys_read,(void *)sys_call_table[__NR_read]);
	write_to_file(fd,message, strlen(message));
	
	sprintf(message, "sys_close\t%d\t%x\t%x\n",__NR_close,(void *)sysmap_sys_read,(void *)sys_call_table[__NR_close]);
	write_to_file(fd,message, strlen(message));	
	
	sprintf(message, "sys_getdents\t%d\t%x\t%x\n",__NR_getdents,(void *)sysmap_sys_getdents,(void *)sys_call_table[__NR_getdents]);
	write_to_file(fd,message, strlen(message));
	
	sprintf(message, "sys_getdents64\t%d\t%x\t%x\n",__NR_getdents64,(void *)sysmap_sys_getdents64,(void *)sys_call_table[__NR_getdents64]);
	write_to_file(fd,message, strlen(message));
	
	sprintf(message, "sys_kill\t%d\t%x\t%x\n",__NR_kill,(void *)sysmap_sys_kill,(void *)sys_call_table[__NR_kill]);
	write_to_file(fd,message, strlen(message));
	
	sprintf(message, "recvmsg\t%d\t%x\t%x\n",__NR_recvmsg,sysmap_sys_recvmsg,sys_call_table[__NR_recvmsg]);
	write_to_file(fd,message, strlen(message));
/*	
	sprintf(message, "filldir64\t%x\t%x\n",sysmap_filldir64,sys_call_table[__NR_filldir64]);
	write_to_file(fd,message, strlen(message));
	
	
	sprintf(message, "sys_readdir\t89\t%x\t%x\n",(void *)sysmap_sys_old_readdir,(void *)sys_call_table[89]);
	write_to_file(fd,message, strlen(message));
	*/
/*	
	if((void *)sys_call_table[__NR_read] == (void *) sysmap_sys_read) {
		strncpy(message, "read       - OK\n", 64);
		write_to_file(fd,message, strlen(message));
	} else {
		hooked_syscalls++;
		strncpy(message, "read       - NOT OK!\n", 64);
		write_to_file(message, strlen(message));
	}
	
	if((void *)sys_call_table[__NR_getdents] == (void *) sysmap_sys_getdents) {
		strncpy(message, "getdents   - OK\n", 64);
		write_to_file(message, strlen(message));
	} else {
		hooked_syscalls++;
		strncpy(message, "getdents   - NOT OK!\n", 64);
		write_to_file(message, strlen(message));
	}
	
	if((void *)sys_call_table[__NR_getdents64] == (void *) sysmap_sys_getdents64) {
		strncpy(message, "getdents64 - OK\n", 64);
		write_to_file(message, strlen(message));
	} else {
		hooked_syscalls++;
		strncpy(message, "getdents64 - NOT OK!\n", 64);
		write_to_file(message, strlen(message));
	}
	
	if((void *)sys_call_table[__NR_recvmsg] == (void *) sysmap_sys_recvmsg) {
		strncpy(message, "recvmsg    - OK\n", 64);
		write_to_file(message, strlen(message));
	} else {
		hooked_syscalls++;
		strncpy(message, "recvmsg    - NOT OK!\n", 64);
		write_to_file(message, strlen(message));
	}
	
	if((void *)sys_call_table[__NR_open] == (void *) sysmap_sys_open) {
		strncpy(message, "open       - OK\n", 64);
		write_to_file(message, strlen(message));
	} else {
		hooked_syscalls++;
		strncpy(message, "open       - NOT OK!\n", 64);
		write_to_file(message, strlen(message));
	}
	
	if((void *)sys_call_table[__NR_close] == (void *) sysmap_sys_close) {
		strncpy(message, "close      - OK\n", 64);
		write_to_file(message, strlen(message));
	} else {
		hooked_syscalls++;
		strncpy(message, "close      - NOT OK!\n", 64);
		write_to_file(message, strlen(message));
	}
	
	if((void *)sys_call_table[__NR_readlink] == (void *) sysmap_sys_readlink) {
		strncpy(message, "readlink   - OK\n", 64);
		write_to_file(message, strlen(message));
	} else {
		hooked_syscalls++;
		strncpy(message, "readlink   - NOT OK!\n", 64);
		write_to_file(message, strlen(message));
	}
	
	if((void *)sys_call_table[__NR_readlinkat] == (void *) sysmap_sys_readlinkat) {
		strncpy(message, "readlinkat - OK\n", 64);
		write_to_file(message, strlen(message));
	} else {
		hooked_syscalls++;
		strncpy(message, "readlinkat - NOT OK!\n", 64);
		write_to_file(message, strlen(message));
	}
	
	if((void *)sys_call_table[__NR_kill] == (void *) sysmap_sys_kill) {
		strncpy(message, "kill       - OK\n", 64);
		write_to_file(message, strlen(message));
	} else {
		hooked_syscalls++;
		strncpy(message, "kill       - NOT OK!\n", 64);
		write_to_file(message, strlen(message));
	}
	
	memset(message, 0, 128);
	sprintf(message, "There are %u manipulated pointers in the system call table.\n", hooked_syscalls);
	write_to_file(message, strlen(message));
	
	/* log our current op */
/*	strncpy(message, "\n[Checking the first bytes of some system calls and other important functions...]\n", 128);
	write_to_file(message, strlen(message));
	
	hooked_syscalls = 0;

	/* check the first parts of memory */
/*	if(memcmp(original_read, (void *) sysmap_sys_read, sizeof(unsigned int)*4) != 0) {
		
		memcpy(tmp, (void *) sysmap_sys_read, sizeof(unsigned int)*4);
		memset(message, 0, 128);
		sprintf(message, "read            - %08X %08X %08X %08X\n", tmp[0], tmp[1], tmp[2], tmp[3]);
		memset(message+127, '\0', 1);
		write_to_file(message, strlen(message));
		hooked_syscalls++;
		
	} else {
		
		strncpy(message, "read            - OK\n", 64);
		write_to_file(message, strlen(message));
		
	}
	
	if(memcmp(original_getdents, (void *) sysmap_sys_getdents, sizeof(unsigned int)*4) != 0) {
		
		memcpy(tmp, (void *) sysmap_sys_getdents, sizeof(unsigned int)*4);
		memset(message, 0, 128);
		sprintf(message, "getdents        - %08X %08X %08X %08X\n", tmp[0], tmp[1], tmp[2], tmp[3]);
		memset(message+127, '\0', 1);
		write_to_file(message, strlen(message));
		hooked_syscalls++;
		
	} else {
		
		strncpy(message, "getdents        - OK\n", 64);
		write_to_file(message, strlen(message));
		
	}
	
	if(memcmp(original_getdents64, (void *) sysmap_sys_getdents64, sizeof(unsigned int)*4) != 0) {

		memcpy(tmp, (void *) sysmap_sys_getdents64, sizeof(unsigned int)*4);
		memset(message, 0, 128);
		sprintf(message, "getdents64      - %08X %08X %08X %08X\n", tmp[0], tmp[1], tmp[2], tmp[3]);
		memset(message+127, '\0', 1);
		write_to_file(message, strlen(message));
		hooked_syscalls++;
		
	} else {
		
		strncpy(message, "getdents64      - OK\n", 64);
		write_to_file(message, strlen(message));
		
	}
	
	if(memcmp(original_recvmsg, (void *) sysmap_sys_recvmsg, sizeof(unsigned int)*4) != 0) {

		memcpy(tmp, (void *) sysmap_sys_recvmsg, sizeof(unsigned int)*4);
		memset(message, 0, 128);
		sprintf(message, "recvmsg         - %08X %08X %08X %08X\n", tmp[0], tmp[1], tmp[2], tmp[3]);
		memset(message+127, '\0', 1);
		write_to_file(message, strlen(message));
		hooked_syscalls++;
		
	} else {
		
		strncpy(message, "recvmsg         - OK\n", 64);
		write_to_file(message, strlen(message));
		
	}
	
	if(memcmp(original_open, (void *) sysmap_sys_open, sizeof(unsigned int)*4) != 0) {
		
		memcpy(tmp, (void *) sysmap_sys_open, sizeof(unsigned int)*4);
		memset(message, 0, 128);
		sprintf(message, "open            - %08X %08X %08X %08X\n", tmp[0], tmp[1], tmp[2], tmp[3]);
		memset(message+127, '\0', 1);
		write_to_file(message, strlen(message));
		hooked_syscalls++;
		
	} else {
		
		strncpy(message, "open            - OK\n", 64);
		write_to_file(message, strlen(message));
		
	}
	
	if(memcmp(original_close, (void *) sysmap_sys_close, sizeof(unsigned int)*4) != 0) {
		
		memcpy(tmp, (void *) sysmap_sys_close, sizeof(unsigned int)*4);
		memset(message, 0, 128);
		sprintf(message, "close           - %08X %08X %08X %08X\n", tmp[0], tmp[1], tmp[2], tmp[3]);
		memset(message+127, '\0', 1);
		write_to_file(message, strlen(message));
		hooked_syscalls++;
		
	} else {
		
		strncpy(message, "close           - OK\n", 64);
		write_to_file(message, strlen(message));
		
	}
	
	if(memcmp(original_readlink, (void *) sysmap_sys_readlink, sizeof(unsigned int)*4) != 0) {
		
		memcpy(tmp, (void *) sysmap_sys_readlink, sizeof(unsigned int)*4);
		memset(message, 0, 128);
		sprintf(message, "readlink        - %08X %08X %08X %08X\n", tmp[0], tmp[1], tmp[2], tmp[3]);
		memset(message+127, '\0', 1);
		write_to_file(message, strlen(message));
		hooked_syscalls++;
		
	} else {
		
		strncpy(message, "readlink        - OK\n", 64);
		write_to_file(message, strlen(message));
		
	}	
	
	if(memcmp(original_readlinkat, (void *) sysmap_sys_readlinkat, sizeof(unsigned int)*4) != 0) {
		
		memcpy(tmp, (void *) sysmap_sys_readlinkat, sizeof(unsigned int)*4);
		memset(message, 0, 128);
		sprintf(message, "readlinkat      - %08X %08X %08X %08X\n", tmp[0], tmp[1], tmp[2], tmp[3]);
		memset(message+127, '\0', 1);
		write_to_file(message, strlen(message));
		hooked_syscalls++;
		
	} else {
		
		strncpy(message, "readlinkat      - OK\n", 64);
		write_to_file(message, strlen(message));
		
	}
	
	if(memcmp(original_kill, (void *) sysmap_sys_kill, sizeof(unsigned int)*4) != 0) {
		
		memcpy(tmp, (void *) sysmap_sys_kill, sizeof(unsigned int)*4);
		memset(message, 0, 128);
		sprintf(message, "kill            - %08X %08X %08X %08X\n", tmp[0], tmp[1], tmp[2], tmp[3]);
		memset(message+127, '\0', 1);
		write_to_file(message, strlen(message));
		hooked_syscalls++;
		
	} else {
		
		strncpy(message, "kill            - OK\n", 64);
		write_to_file(message, strlen(message));
		
	}
		
	if(memcmp(original_packet_rcv, (void *) sysmap_packet_rcv, sizeof(unsigned int)*4) != 0) {
		
		memcpy(tmp, (void *) sysmap_packet_rcv, sizeof(unsigned int)*4);
		memset(message, 0, 128);
		sprintf(message, "packet_rcv      - %08X %08X %08X %08X\n", tmp[0], tmp[1], tmp[2], tmp[3]);
		memset(message+127, '\0', 1);
		write_to_file(message, strlen(message));
		hooked_syscalls++;
		
	} else {
		
		strncpy(message, "packet_rcv      - OK\n", 64);
		write_to_file(message, strlen(message));
		
	}
	
	if(memcmp(original_packet_rcv_spkt, (void *) sysmap_packet_rcv_spkt, sizeof(unsigned int)*4) != 0) {

		memcpy(tmp, (void *) sysmap_packet_rcv_spkt, sizeof(unsigned int)*4);
		memset(message, 0, 128);
		sprintf(message, "packet_rcv_spkt - %08X %08X %08X %08X\n", tmp[0], tmp[1], tmp[2], tmp[3]);
		memset(message+127, '\0', 1);
		write_to_file(message, strlen(message));
		hooked_syscalls++;
		
	} else {
		
		strncpy(message, "packet_rcv_spkt - OK\n", 64);
		write_to_file(message, strlen(message));
		
	}
	
	if(memcmp(original_tpacket_rcv, (void *) sysmap_tpacket_rcv, sizeof(unsigned int)*4) != 0) {
		
		memcpy(tmp, (void *) sysmap_tpacket_rcv, sizeof(unsigned int)*4);
		memset(message, 0, 128);
		sprintf(message, "tpacket_rcv     - %08X %08X %08X %08X\n", tmp[0], tmp[1], tmp[2], tmp[3]);
		memset(message+127, '\0', 1);
		write_to_file(message, strlen(message));
		hooked_syscalls++;
		
	} else {
		
		strncpy(message, "tpacket_rcv     - OK\n", 64);
		write_to_file(message, strlen(message));
		
	}
	
	memset(message, 0, 128);
	sprintf(message, "There are %u manipulated functions.\n", hooked_syscalls);
	write_to_file(message, strlen(message));
*/	
	return 0;
}
