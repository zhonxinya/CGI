#ifndef _TASKMANGER_H_
#define _TASKMANGER_H_
#include <sys/ipc.h>
#include <sys/shm.h>
#define IPCKEY 0x344378
#define IPCKEY_TASK 0x444278//维护任务序列 TASK的变量还有任务配置的客户端信息  客户端信息中由资源序列。
#define IPCKEY_SEQ  0x555278//维护资源序列 包含资源块本身和其他描述信息 资源块本身具有序列信息
























void master();
void worker();
#endif