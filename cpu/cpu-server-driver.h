#ifndef _CPU_SERVER_DRIVER_H_
#define _CPU_SERVER_DRIVER_H_

int server_driver_init(int restore);
int server_driver_deinit(void);
//int server_driver_checkpoint(const char *path, int dump_memory, unsigned long prog, unsigned long vers);
//int server_driver_restore(const char *path);
int server_driver_elf_restore(void);
int server_driver_function_restore(void);

int server_driver_var_restore(void);

#endif //_CPU_SERVER_DRIVER_H_
