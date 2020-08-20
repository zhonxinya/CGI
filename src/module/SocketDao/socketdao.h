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
#define OK     "HTTP/1.1  200 OK\r\n   \
                Content-Length: null   \
                Server: jdbhttpd/0.1.0\r\n  \
                Content-type: text/html charset=utf-8\r\n \
                Date: " __DATE__ __TIME__"GMT\r\n\r\n"
#define SERVER_STRING "Server: jdbhttpd/0.1.0\r\n"
int server(u_short *port);
int send_file(int client ,char* path);
void accept_request(void *arg);
int get_line(int sock, char *buf);

#define PUTS(client,str,...) {  \
                sprintf(buf,"%s\r\n",str);    \
                send(client,buf,sizeof(buf),0); \
                memset(buf,'\0',sizeof(buf));   \
}
#define CLIENT client
#define GETS(buf)  get_line(CLIENT,buf)            

#endif