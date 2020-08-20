#include "taskmanger.h"
#include "sdata.h"
#include "log.h"

task* t1,t2,t3;
task *temp;
struct list_head head,*pos;
void worker(){
    //功能由一个个小任务实现
    //先读取任务号 获取  code和sequence 然后调取资源运作  发送数据或者接收数据、处理数据
    //负责监听请求  
    //任务处理完毕告知主线程
    //单个资源使用完毕告知主线程  实时更新数据  但在任务未完成前不准放弃数据，任务完成则释放资源
}
void master(){
    //负责调度资源和启动
    //负责发送任务号 负责接收IPC这类的信息，回收或者创建资源区
    client_info c1;
    INIT_LIST_HEAD(&head);                    //创建链表函数
    strcat(c1.Ip,"127");strcat(c1.Method,"POST");strcat(c1.Path,"/index");c1.sock=0;c1.code=0;
    t1=get_task(&c1,1);

   // printf("%s",t1->client_info->Ip);
    list_add_tail( &t1->node,&(head));


    list_for_each(pos,&(head))
    {
        temp = list_entry(pos,task,node);
            if(temp->id == 1 ) list_del(&temp->node);;
    }

    

        list_for_each(pos,&(head))
    {
        temp = list_entry(pos,task,node);
            printf("%d\n",temp->id);
    }
}

void  deamon(){
        //负责守护进程
        //检测异常状况，重启程序，恢复上下文，向主进程发送保留资源信号，再处理
}

