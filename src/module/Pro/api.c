#include "api.h"
#include<sys/types.h>
#include "sdata.h"
#include <sys/ipc.h>
#include <sys/msg.h>
#include<stdio.h>
 typedef struct msbuf
{
    long msg_type;
    dmi data;
}ms;
int cmpfunc1 (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int cmpfunc2 (const void * a, const void * b)
{
   return ( *(int*)b - *(int*)a );
}


//排序
int 
sort_int_min_max(int* src, int n){
     qsort(src, n, sizeof(int), cmpfunc1);
     return 0;
}

int 
sort_int_max_min(int* src, int n){
     qsort(src, n, sizeof(int), cmpfunc2);
     return 0;
}

//打印
int printInt(int * in,int n){
    for(int i=0;i<n;i++){
        printf("%d ",in[i]);
    }
    printf("\n");
    return 0;
}

int key(){
        key_t key=ftok(".",3);
    int msgid;
    ms pp;
    int send;
    dmi data; 
    dmi recv;
    data.code=1;
    data.sequence=1;
    pp.msg_type=0;
    pp.data=data;
    msgid=msgget(key,IPC_CREAT);
    msgsnd(msgid,&pp,sizeof(data),0);
    if(key<0){
        perror("wrong key\n");
    }

    int pid=fork();
    if(pid == 0){
        msgid=msgget(key,0);
        msgrcv(msgid,&pp,sizeof(data),1,0);
        printf("code %d seq: %d\n",pp.data.code,pp.data.sequence);
    }
    return 0;
}