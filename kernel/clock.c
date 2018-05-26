
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                               修改 clock.c
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
代码回到第六章，使主进程和副进程能够同时进行
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                                                    Jeven, 2018
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include "type.h"
#include "const.h"
#include "protect.h"
#include "string.h"
#include "proc.h"
#include "tty.h"
#include "console.h"
#include "global.h"
#include "proto.h"


/*======================================================================*
                           clock_handler
 *======================================================================*/
PUBLIC void clock_handler(int irq)
{
	// ticks++;
	// p_proc_ready->ticks--;

	// if (k_reenter != 0) {
	// 	return;
	// }

	// if (p_proc_ready->ticks > 0) {
	// 	return;
	// }

	// schedule();

  // 下面这几行代码，使得程序可以运行在不同特权级之上，普通的用户进程和系统任务区分开来，可以同时运行。
  ticks++;
  
  if (k_reenter != 0) {
    return;
  }
  
  p_proc_ready++;
  if(p_proc_ready>=proc_table+NR_TASKS){
    p_proc_ready=proc_table;   
  }


/*======================================================================*
                              milli_delay
 *======================================================================*/
PUBLIC void milli_delay(int milli_sec)
{
        int t = get_ticks();

        while(((get_ticks() - t) * 1000 / HZ) < milli_sec) {}
}

/*======================================================================*
                           init_clock
 *======================================================================*/
PUBLIC void init_clock()
{
        /* 初始化 8253 PIT */
        out_byte(TIMER_MODE, RATE_GENERATOR);
        out_byte(TIMER0, (u8) (TIMER_FREQ/HZ) );
        out_byte(TIMER0, (u8) ((TIMER_FREQ/HZ) >> 8));

        put_irq_handler(CLOCK_IRQ, clock_handler);    /* 设定时钟中断处理程序 */
        enable_irq(CLOCK_IRQ);                        /* 让8259A可以接收时钟中断 */
}


