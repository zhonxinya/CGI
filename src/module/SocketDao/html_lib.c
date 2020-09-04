#include"html_lib.h"
#include<string.h>
void get_code(int code,char*buf){
    switch(code){
        case 200:
                strcat(buf,"HTTP/1.1 200 OK");
                break;
        case 302:
                strcat(buf,"HTTP/1.1 302 Moved Temporarily");
                break;
        case 400:
                strcat(buf,"HTTP/1.1 400 Bad Request");
                break;
        case 404:
                strcat(buf,"HTTP/1.1 404 NOT FOUND");
                break;
        case 501:
                sprintf(buf,"HTTP/1.1  501 Not Implemented");
                break;
        default :
                buf = NULL;
                break;
    }
}


void my_header(int code,int age,int len){
    char buf[256];
    get_code(code,buf);
    puts(buf);
    sprintf(buf,"Allow: GET POST HEAD\r\n" );
    puts(buf);
    sprintf(buf,"Age: %d\r\n",age );
    puts(buf);
    sprintf(buf,"Content-Encoding: gzip\r\n" );
    puts(buf);
    sprintf(buf,"Server:nginx/1.6.3\r\n");
    puts(buf);
    sprintf(buf, __DATE__ __TIME__ " GMT\r\n");
    puts(buf);
    sprintf(buf,"Content-Length: %d\r\n",len);
    puts(buf);
    sprintf(buf,"Cache-Control: max-age=3600\r\n");
    puts(buf);
}