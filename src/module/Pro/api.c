#include "api.h"
#include<sys/types.h>
#include "sdata.h"
#include <sys/ipc.h>
#include <sys/msg.h>
#include<stdio.h>

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

}