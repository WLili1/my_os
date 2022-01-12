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
#include "../lib/user/assert.h"
#include "../shell/shell.h"
#include "../device/ide.h"
#include "../lib/kernel/stdio-kernel.h"


void k_thread_a(void*);
void k_thread_b(void*);
void u_prog_a(void);
void u_prog_b(void);

int main(void) {
   put_str("I am kernel\n");
    init_all();

    /*************    写入应用程序    *************/
//   uint32_t file_size = 5698;
//   uint32_t sec_cnt = DIV_ROUND_UP(file_size, 512);
//   struct disk* sda = &channels[0].devices[0];
//   void* prog_buf = sys_malloc(file_size);
//   ide_read(sda, 300, prog_buf, sec_cnt);
//   int32_t fd = sys_open("/cat", O_CREAT|O_RDWR);
//   if (fd != -1) {
//      if(sys_write(fd, prog_buf, file_size) == -1) {
//         printk("file write error!\n");
//         while(1);
//      }
//   }
/*************    写入应用程序结束   *************/
    cls_screen();
    console_put_str("[rabbit@localhost /]$ ");
    thread_exit(running_thread(), true);
   return 0;
}

