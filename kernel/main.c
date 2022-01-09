#include "../lib/kernel/print.h"
#include "init.h"
#include "../thread/thread.h"
#include "interrupt.h"
#include "../device/console.h"
#include "../userprog/process.h"
#include "../userprog/syscall-init.h"
#include "../lib/user/syscall.h"
#include "../lib/stdio.h"
#include "memory.h"
#include "../fs/fs.h"
#include "string.h"
#include "../fs/dir.h"

void k_thread_a(void*);
void k_thread_b(void*);
void u_prog_a(void);
void u_prog_b(void);

int main(void) {
   put_str("I am kernel\n");
    init_all();
/********  测试代码  ********/
    struct stat obj_stat;
    sys_stat("/", &obj_stat);
    printf("/`s info\n   i_no:%d\n   size:%d\n   filetype:%s\n", \
	 obj_stat.st_ino, obj_stat.st_size, \
	 obj_stat.st_filetype == 2 ? "directory" : "regular");
    sys_stat("/dir1", &obj_stat);
    printf("/dir1`s info\n   i_no:%d\n   size:%d\n   filetype:%s\n", \
	 obj_stat.st_ino, obj_stat.st_size, \
	 obj_stat.st_filetype == 2 ? "directory" : "regular");
/********  测试代码  ********/
   while(1);
   return 0;
}

/* init进程 */
void init(void) {
    uint32_t ret_pid = fork();
    if(ret_pid) {
        printf("i am father, my pid is %d, child pid is %d\n", getpid(), ret_pid);
    } else {
        printf("i am child, my pid is %d, ret pid is %d\n", getpid(), ret_pid);
    }
    while(1);
}
