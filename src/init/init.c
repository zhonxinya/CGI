#include <signal.h>
#include <poll.h>
#include <sys/epoll.h>
#include <sys/time.h>
#include "html_lib.h"
#include "taskmanger.h"
#include "init.h"
#include "sdata.h"
#include "socketdao.h"
#include "log.h"
#include "fmanager.h"
void AcceptConn(int srvfd);
void RecvData(int fd);
char* find_key(char* key,struct list_head* head);
Msg* get_msg(char* key,struct list_head* head);
Msg** get_msg_all(char* key,struct list_head* head,int* num);
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
             // perror( "epoll error\n");
              //close (eventList[i].data.fd);
              continue;
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
                   // close(eventList[i].data.fd);
                    exit(1);
                }        
            }
            else if(eventList[i].events & EPOLLIN)
            {
                pid_t pid;
                pid=fork();
                sleep(0.1);
                if(pid == 0){   
                    RecvData(eventList[i].data.fd);
                }else if(pid <0){
                    perror("connect pid");
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
        printf("Accept Connection: %d\n", confd);
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

int add_msg(Msg* msg,struct list_head* head){
    struct list_head  *pos;
    list_for_each(pos,head)
    {
        Msg *tmp= list_entry(pos,Msg,list);
        if(  strcmp(msg->json.key,tmp->json.key) == 0  &&  strcmp(msg->json.value,tmp->json.value) == 0) {
         return 0;
        }
    }
    list_add(&msg->list,head);
    return 1;
}
//读取数据
void send_file(char* path,int fd){
        FILE *fp;
        char buf[1000];
        fp = fopen(path, "r");
        if (fp == NULL) 
        {
           send_errors( 404, path,NULL,"NOT FOUND");
        }
        else 
        {
            while (fgets(buf, sizeof(buf), fp) != NULL) 
            {
              send( fd, buf, strlen(buf), 0 );  
            }
            fclose(fp);
        }

}

void do_path(char* path,char*qS,int fd){
    int len;
    if( strcmp(path,"/") == 0  || strcmp(path,"index") == 0){
        strcpy(path,"src/web/index.html");
        len=get_file_size_by_stat(path);
         if(len >0){
            pid_t pid=fork();
                if(pid == 0){
                    send_headers( 200, "OK", NULL,get_mime_type(path), len, -1 );
                    send_file(path,fd);
                }
         }
         //send_errors( 200, path,NULL, qS);
    }else{
        char p[128];
        memset(p,'\0',sizeof(p));
        strcpy(p,"src/web");
        strcat(p,path);
        pid_t pid=fork();
        if(pid == 0){
            len=get_file_size_by_stat(p);
            send_headers( 200, "OK", NULL,get_mime_type(p), len, -1 );
            send_file(p,fd);
        }
       
    }
   
}

void  handle_request(int fd,struct list_head *head)
{
    int fd1=dup(fd);
    dup2(fd,STDOUT_FILENO);
    //printf("start to handle\n");
    char* method;
    char* path;  
    method=find_key("method",head);
    path=find_key("path_row",head);
    if(method == NULL || path == NULL) return ;
    if(strcmp(method,"GET") ==0 )
    {
        if(path != NULL)
        {
            char* tok;
            char p[128];
            char qS[128];
            if((tok=strstr(path,"?")) != NULL)
            {
                sscanf(path,"%[^?]?%s",p,qS);
            }else
            {
                 sscanf(path,"%s",p);
                 strcpy(qS,"");
            }

            do_path(p,qS,fd);

        }
    }else if(strcmp(method,"POST")==0){
       // send_headers( 200, "OK", NULL,get_mime_type("*.js"), -1, -1 );
       printf("HTTP/1.1 200 OK\r\n\r\n");

    }
}
void RecvData(int fd)
{
    Msg* msg=(Msg*)malloc(sizeof(Msg));
    int fd1=dup(fd);
    struct list_head head;
    INIT_LIST_HEAD(&head);
    const char s[2] = ":";
    get_line(fd,recvBuf);
    char* tmp1;
    tmp1=strtok(recvBuf," ");
    add_msg(new_msg("method",tmp1),&head);
    tmp1=strtok(NULL," ");
    add_msg(new_msg("path_row",tmp1),&head);
    printf("%s\n",find_key("path_row",&head));
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
        add_msg(new_msg(key,value),&head);
        memset(recvBuf, 0, 256);
        if(strlen(key) <=2) break;
    }
    
    char* size=find_key("Content-Length",&head);
    if(size !=NULL)  size=strtok(size," ");
    else  size = NULL;
    if(size != NULL  ){ 
        size[strlen(size)-1]='\0';
        int si=atoi(size);
        recv(fd, recvBuf, si, 0);
        if(recvBuf[0] == '{' && recvBuf[strlen(recvBuf)-1] =='}'){
             add_msg(new_msg("json_data",recvBuf),&head);
        }else{
             add_msg(new_msg("dic_data",recvBuf),&head);
        }
    }
    handle_request(fd,&head);
}
char* find_key(char* key,struct list_head* head){
        char* value=(char*)malloc(sizeof(char*)*256);
        bzero(value,256);
        struct list_head  *pos;
        list_for_each(pos,head)
        {
            Msg *msg= list_entry(pos,Msg,list);
            if(  strcmp(msg->json.key,key) == 0 ) {
            //   printf("key:%s value:%s\n",msg->json.key,msg->json.value); 
               strcpy(value,msg->json.value);
               return value;
            }
        }
        return NULL;
}
Msg* get_msg(char* key,struct list_head* head){
        struct list_head  *pos;
        list_for_each(pos,head)
        {
            Msg *msg= list_entry(pos,Msg,list);
            if(  strcmp(msg->json.key,key) == 0 ) {
               return msg;
            }
        }
        return NULL;
}
Msg** get_msg_all(char* key,struct list_head* head,int* num){
        Msg** tmp=(Msg**)malloc(sizeof(Msg)*100);
        bzero(tmp,sizeof(Msg)*100);
        int count=0;
        struct list_head  *pos;
        list_for_each(pos,head)
        {
            Msg *msg= list_entry(pos,Msg,list);
            if(  strcmp(msg->json.key,key) == 0 ) {
                tmp[count++]=msg;  
            }
        }
        *num=count;
        if(count == 0) return NULL;
        else           return tmp;
}