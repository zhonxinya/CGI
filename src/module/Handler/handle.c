#include<stdio.h>

typedef struct fun_lab{
    char* var_name;
    int(*get)(int ,int);
    int(*set)(int ,int);
    char* result;
} fun_lab;
fun_lab[]={
    {"method",NULL,NULL,NULL};
};
int html_parser(){




}
void handler(int sig){

	printf("sig ：%d\n",sig);
}
void wait_pid_handle(int sig){
	pid_t pid;
	int stat;
	pid=wait(&stat);
	return ;
}



void handle(){
    
}