#ifndef _SDATA_H_
#define _SDATA_H
#include "list.h"
/*
自定义结构体的使用
*/
//
/*
    最小资源块结构体    
    code表示 使用类型    sequence表示资源序号 blong表示所属socket即管道的方向
    管道类型 0表示 输入  1 表示 输出    


*/
typedef struct Data_Min_Info{
    int code;//资源类型
    int sequence;//资源序号
    char  data[256];
 }  dmi ;

/*
    资源管理；
    code表示资源类型  sequence是分配的序号，长度维持在一定长度，避免资源泄露
*/
 typedef struct Sequence{//遍历队列找到没有占用的序号，分配给新任务
     dmi data;
     int lock;//0 锁  1 解锁  分配给进程后上锁，处理完解锁，释放序号 
     struct list_head node;
 } seq;

 typedef struct Client_Info{//一次任务请求信息
     char Ip[20];//访问者IP地址
     char Method[20];//访问方法
     char Path[128];//访问路径
     char queryString[1000];
     int  sock;//管道号
     int  code;//任务类型代码
 }client_info;

 typedef struct Task{//
     int id;// 任务号
     int lock;//0 锁  1 解锁  分配给进程后上锁，处理完解锁，释放序号 
     client_info* client_info;//客户数据封装在任务中
     struct list_head node;
 }task;

task*  get_task(client_info* client,int id);
#endif