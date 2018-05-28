
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                           修改 global.c
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
新增一些全局变量
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                                                    Jeven, 2018
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/* EXTERN is defined as extern except in global.c */
#ifdef	GLOBAL_VARIABLES_HERE
#undef	EXTERN
#define	EXTERN
#endif

EXTERN	int		ticks;

EXTERN	int		disp_pos;
EXTERN	u8		gdt_ptr[6];	// 0~15:Limit  16~47:Base
EXTERN	DESCRIPTOR	gdt[GDT_SIZE];
EXTERN	u8		idt_ptr[6];	// 0~15:Limit  16~47:Base
EXTERN	GATE		idt[IDT_SIZE];

EXTERN	u32		k_reenter;

EXTERN	TSS		tss;
EXTERN	PROCESS*	p_proc_ready;

EXTERN	int		nr_current_console;

extern	PROCESS		proc_table[];
extern	char		task_stack[];
extern  TASK            task_table[];
extern	irq_handler	irq_table[];
extern	TTY		tty_table[];
extern  CONSOLE         console_table[];

// 新增查找模式
EXTERN int esc_mode;  //判断是否处于查找模式
EXTERN int is_show_result; //判断是不是在显示查找结果

EXTERN u8 input_char_array[10000]; //记录非查找模式下键盘输入的字符
EXTERN int input_char_position_array[10000]; //记录非查找模式下输入字符对应屏幕上的位置
EXTERN int input_index; //记录输入字符数组下标

EXTERN u8 find_char_array[10000]; //记录查找模式下键盘输入的字符
EXTERN int find_char_position_array[10000]; //记录查找模式下输入字符对应屏幕上的位置
EXTERN int find_index; //记录查找字符数组下标

