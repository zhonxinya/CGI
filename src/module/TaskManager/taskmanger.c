#include "taskmanger.h"
#include "sdata.h"
#include "log.h"
void worker(){
    //功能由一个个小任务实现
    //先读取任务号 获取  code和sequence 然后调取资源运作  发送数据或者接收数据、处理数据
    //负责监听请求  
    //任务处理完毕告知主线程
    //单个资源使用完毕告知主线程  实时更新数据  但在任务未完成前不准放弃数据，任务完成则释放资源
}
void master(){

}

void  deamon(){
        //负责守护进程
        //检测异常状况，重启程序，恢复上下文，向主进程发送保留资源信号，再处理
}

