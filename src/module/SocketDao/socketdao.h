#ifndef _SOCKETDAO_H_
#define _SOCKETDAO_H
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <ctype.h>
#include <strings.h>
#include <string.h>
#include <sys/stat.h>
#include <pthread.h>
#include <sys/wait.h>
#include <stdlib.h>
#include<string.h>
#include <stdint.h>
#define ISspace(x) isspace((int)(x))
#define STDIN   0
#define STDOUT  1
#define STDERR  2
int server(u_short *port);
void accept_request(void *arg);
int get_line(int sock, char *buf);
void err_msg(int code,char* msg1,char* msg2);
         

#endif