#include "socketdao.h"
#include "sdata.h"
#include "../Log/log.h"



    int server(u_short *port){
        int httpd = 0;
        int on = 1;
        struct sockaddr_in name;
        httpd = socket(PF_INET, SOCK_STREAM, 0);
        if (httpd == -1)
            error("socket");
        memset(&name, 0, sizeof(name));
        name.sin_family = AF_INET;
        name.sin_port = htons(*port);
        name.sin_addr.s_addr = htonl(INADDR_ANY);
        if ((setsockopt(httpd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on))) < 0)  
        {  
            error("setsockopt failed");
        }
        if (bind(httpd, (struct sockaddr *)&name, sizeof(name)) < 0)
            error("bind");
        if (*port == 0)  /* if dynamically allocating a port */
        {
            socklen_t namelen = sizeof(name);
            if (getsockname(httpd, (struct sockaddr *)&name, &namelen) == -1)
                error("getsockname");
        *   port = ntohs(name.sin_port);
        }
        if (listen(httpd, 5) < 0)
            error("listen");
        return(httpd);
}





int get_line(int sock, char *buf)
{
    int i = 0;
    char c = '\0';
    int n;
    while ((i < 128) && (c != '\n'))
    {
        n = recv(sock, &c, 1, 0);
       
        /* DEBUG printf("%02X\n", c); */
        if (n > 0)
        {
        
            if (c == '\r')
            {
                n = recv(sock, &c, 1, MSG_PEEK);
                /* DEBUG printf("%02X\n", c); */
                if ((n > 0) && (c == '\n'))
                    recv(sock, &c, 1, 0);
                else
                    c = '\n';
            }
            buf[i] = c;
            i++;
        }
        else
            c = '\n';
    }
    buf[i] = '\0';
    return(i);
}




int  file_size(char* path){
    FILE *fp;
    fp = fopen(path , "r");
    if(fp == NULL){
        perror("cant open\n");
        exit(1);
    }
    //if(fp == )
    fseek( fp , 0 , SEEK_END );
    int file_size;
    file_size = ftell( fp );
    fclose(fp);
    return file_size;
}






void accept_request(void *arg){

}


