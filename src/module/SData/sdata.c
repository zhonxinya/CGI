#include "sdata.h"
#include "log.h"

    task*  get_task(client_info* client,int id){//在共享内存中新建一个task结构体
       task *head;
       head =malloc(sizeof(client)+sizeof(task)+sizeof(struct list_head)+10);
       head->id=id;
       head->lock=0;
       head->client_info=client;//初始化表头信息
       return head;
   }





