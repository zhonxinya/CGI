#include"html_lib.h"
#include<string.h>
void get_code(int code){
    switch(code){
        case 200:
                printf("HTTP/1.1 200 OK \r\n");
                break;
        case 302:
                printf("HTTP/1.1 302 Moved Temporarily\r\n");
                break;
        case 400:
                printf("HTTP/1.1 400 Bad Request\r\n");
                break;
        case 404:
                printf("HTTP/1.1 404 NOT FOUND\r\n");
                break;
        case 501:
                printf("HTTP/1.1  501 Not Implemented\r\n");
                break;
        default :
                break;
    }
}


void my_header(int code){
        get_code(code);
        printf("Allow: GET,POST,HEAD\r\n" );
        printf("Accept-Encoding: gzip, deflate\r\n");
     //   printf("Content-Encoding: gzip,deflate\r\n");
        printf("Server: nginx/1.6.3\r\n");
        printf("Cache-Control: max-age=3600\r\n");
      //  printf("Content-Length: %d \r\n\r\n",len);
}