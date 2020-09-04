#include "init.h"
#include "sdata.h"
#include "socketdao.h"
#include "log.h"
#include "taskmanger.h"
#include <signal.h>
#include "api.h"
#include <poll.h>
#include <sys/epoll.h>
#include <sys/time.h>
void AcceptConn(int srvfd);
void RecvData(int fd);
char* find_key(char* key,struct list_head* head);
char recvBuf[256];
int epollfd;
void init(){
    int ser=0;
    int client_sock=0;

    char buf[1024];
    u_short port =5500;
    ser=server(&port);
    struct sockaddr_in client_name;
    struct epoll_event eventList[126];
    socklen_t  client_name_len = sizeof(client_name);
    pthread_t acccpet_threda_new; 
    epollfd = epoll_create(126);
    struct epoll_event event;
    event.events = EPOLLIN|EPOLLET;
    event.data.fd = ser;
    //add Event
    if(epoll_ctl(epollfd, EPOLL_CTL_ADD, ser, &event) < 0)
    {
        printf("epoll add fail : fd = %d\n", ser);
        return ;
    }
        while(1)
    {            
        //epoll_wait
        int ret = epoll_wait(epollfd, eventList, 128, 2000);
        if(ret < 0)
        {
            perror("epoll error:\n");
            break;
        }
        else if(ret == 0)
        {
            continue;
        }
        
        //直接获取了事件数量,给出了活动的流,这里是和poll区别的关键
        int i = 0;
        for(i=0; i<ret; i++)
        {
            //错误退出
            if ((eventList[i].events & EPOLLERR) ||
                (eventList[i].events & EPOLLHUP) ||
                !(eventList[i].events & EPOLLIN))
            {
              perror( "epoll error\n");
              close (eventList[i].data.fd);
              return ;
            }
            
            if (eventList[i].data.fd == ser)
            {
                pid_t pid;
                pid=fork();
                if(pid == 0){
                    AcceptConn(eventList[i].data.fd);
                }else if(pid <0){
                    perror("connect pid");
                    close(eventList[i].data.fd);
                    exit(1);
                }        
            }
            else
            {
                pid_t pid;
                pid=fork();
                if(pid == 0){
                    RecvData(eventList[i].data.fd);
                }else if(pid <0){
                    perror("connect pid");
                    close(eventList[i].data.fd);
                    exit(1);
                }
                
            }
        }

            
    }
        close(epollfd);
        close(ser);
    }


void AcceptConn(int srvfd)
{
    struct sockaddr_in sin;
    socklen_t len = sizeof(struct sockaddr_in);
    bzero(&sin, len);
    int confd = accept(srvfd, (struct sockaddr*)&sin, &len);
    if (confd < 0)
    {
       printf("bad accept\n");
       return;
    }else
    {
       // printf("Accept Connection: %d", confd);
    }
    //将新建立的连接添加到EPOLL的监听中
    struct epoll_event event;
    event.data.fd = confd;
    event.events =  EPOLLIN|EPOLLET;
    epoll_ctl(epollfd, EPOLL_CTL_ADD, confd, &event);
}
 
Msg* new_msg(char* key,char* value){
    Msg* msg = (Msg*)malloc(sizeof(Msg));
    if(msg != NULL){
        strcat(msg->json.value,value);
        strcat(msg->json.key,key);
        return msg;
    }
    else{
        return NULL;
    }
}
//读取数据
void RecvData(int fd)
{
    Msg* msg=(Msg*)malloc(sizeof(Msg));
    const char s[2] = ":";
    struct list_head head;
    INIT_LIST_HEAD(&head);
    get_line(fd,recvBuf);
    memset(recvBuf, 0, 256);
    while(  get_line(fd,recvBuf)  ){
        char*tmp;
        char key[128]={0};
        char value[128]={0};
        tmp=strtok(recvBuf,s);
        strcpy(key,tmp);
        //printf("\n%s value %s\n",key,value);
        //printf("key:%s value %s\n",key,value);
        tmp =strtok(NULL,s);
        if(tmp != NULL){
            strcpy( value,tmp);
        }
        if(strcmp(key,"Host") == 0){
             tmp =strtok(NULL,s);
             strcat( value,":");
             strcat( value,tmp);
        }
        list_add(&new_msg(key,value)->list,&head);
        memset(recvBuf, 0, 256);
        find_key("Connection",&head);
        if(strlen(key) <=2) break;
    }
    printf("end buf\n");
}
char* find_key(char* key,struct list_head* head){
        char* value=(char*)malloc(sizeof(char*)*256);
        struct list_head  *pos;
        list_for_each(pos,head)
        {
            Msg *msg= list_entry(pos,Msg,list);
            if(  strcmp(msg->json.key,key) == 0 ) {
               printf("key:%s value:%s\n",msg->json.key,msg->json.value); 
               strcat(value,msg->json.value);
               return value;
            }
        }
        return NULL;
}