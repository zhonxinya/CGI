#include "socketdao.h"
#include "sdata.h"
#include "../Log/log.h"
//建立http服务器
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

void getHttpReturn(int code,char*buf){
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
void setAge(char* buf,int age){
        sprintf(buf,"Age: %d",age );
}
void setAllow(char* buf){
    sprintf(buf,"Allow: GET POST HEAD" );
}
void setLocation(char* buf,char* path){
    //"Location: 路径"
    sprintf(buf,"Location: %s",path);
}
void setCatchControl(char* buf){
    sprintf(buf,"Cache-Control: max-age=3600" );
}

void setContentEncoding(char* buf){
    sprintf(buf,"Content-Encoding: gzip" );
}
void setContentLength(char* buf,int len){
    sprintf(buf,"Content-Length: %d",len);
}

void setContenttype_text(char* buf){
    sprintf(buf, "Content-Type: text/html; charset=utf-8");
}
void setDate(char* buf){
    sprintf(buf, __DATE__ __TIME__ "GMT");
}
void setRefesh(int time,char* url,char* buf){
    sprintf(buf,"Refresh: %d; url=%s",time,url);
}
void setServer(char* buf){
    sprintf(buf,"Server:nginx/1.6.3");
}
void setStatus(char* buf){
    sprintf(buf,"Status: 200 OK");
}

int putline(int client,char* line){
        char buf[1000];
        memset(buf,'\0',1000);
        if(line){
            sprintf(buf,"%s\r\n",line);
            write(client,buf,sizeof(buf));
        }
}
void setRecoHeader(int client,int code,int len){
    char buf[128];
    memset(buf,'\0',sizeof(buf));
    getHttpReturn(code,buf);
    putline(client,buf);
   //     memset(buf,'\0',sizeof(buf));
    setContenttype_text(buf);
    putline(client,buf);
     //   memset(buf,'\0',sizeof(buf));
    setDate(buf);
    putline(client,buf);
     //   memset(buf,'\0',sizeof(buf));
    setContentLength(buf,len);
    putline(client,buf);
  //      memset(buf,'\0',sizeof(buf));
    setServer(buf);
    putline(client,strcat(buf,"\r\n"));    
        memset(buf,'\0',sizeof(buf));
}

void send_html(int client,int code,char* data){
    char buf[1000];
    buf[0]='\0';
    int len=sizeof(data)+2;
    setRecoHeader(client,code,len);
    putline(client,data);
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
   

int  send_html_file(int client,char* path){
    printf("start to transer %s",path);
    int size=file_size(path);
    FILE *fp;
    fp=fopen(path,"r");
    if(fp == NULL){
        perror("cant open:");
        return NULL;
     }
    setRecoHeader(client,200,size+1);
    while(!feof(fp))
    {   
        char tmp[256];
        fgets(tmp,sizeof(tmp),fp);
        putline(client,tmp);
    }
    fclose(fp);
    return 1;
    }
int setClient(client_info * c_s){ 
    int client=c_s->sock;
    char  *cat, *qS;
    char buf[256];  
    int cc,len=0;
    do{
        cc=GETS(buf);
        //printf("line %s \n" ,buf);
        if( strstr(buf,"HTTP/1.1") !=NULL ){ 
         //   Log(buf);
            cat=strtok(buf," ");
            strcat(c_s->Method,cat);//获取nethod方法
            cat = strtok(NULL, " ");//
            qS=strtok(cat,"?");
            strcat(c_s->Path,qS);//获取路径
            qS = strtok(NULL, "?");//获取queryString
            if(qS != NULL) strcat(c_s->queryString,qS);
            else strcat(c_s->queryString," ");
            memset(buf,'\0',256);
        }
        else if(strstr(buf,"Host")!=NULL  ){
           // Log(buf);
            cat=strtok(buf,":");
            cat = strtok(NULL, " ");
            strcat(c_s->Ip,cat);
          //  printf("IP: %s",cat);
        }
        else if(strstr(buf,"Accept-Encoding:")!=NULL  ){
           // Log("Accept-Encoding");
        }
        else if(strstr(buf,"Connection:")!=NULL  ){
          //  Log(buf);
          //  Log("Connection");
        }
        else if(strstr(buf,"Accept:")!=NULL  ){
          //  Log("Accept");
        }
        else if(strstr(buf,"Accept-Language:")!=NULL  ){
         //   Log(buf);
        }
        else if(strstr(buf,"Accept-Charset")!=NULL  ){
            Log(buf);
        }
        else if(strstr(buf,"Cache-Control:")!=NULL  ){
         //   Log(buf);
           // Log("Cache-Control");
        }
        else if(strstr(buf,"Upgrade-Insecure-Requests:")!=NULL  ){
           // Log("Upgrade-Insecure-Requests");
        }
        else if(strstr(buf,"User-Agent")!=NULL  ){
          //  Log(buf);
        } 
        else if(strstr(buf,"Referer:")!=NULL  ){
           // Log("Accept");
        
        } 
        else if(strstr(buf,"Cookie:")!=NULL  ){
           // Log("Accept");
        }else if(strstr(buf,"Content-Length:")!=NULL)
        {
            cat=strtok(buf,":");
            cat = strtok(NULL, " ");
            len=atoi(cat);
            printf("\n%d\n",len);
        }
        else if(buf == "\r\n\r\n"){
            break;
        }
    }while(cc >=2);
    if(strstr(c_s->Method,"POST")!=NULL){
        memset(buf,'\0',128);
        recv(client,buf,len,MSG_WAITALL);//这里长度改为content-lrngth长度，然后解析
        strcpy(c_s->queryString,buf);
    }
  //  close(client);
    Log("End of a request\n");
    return 1;
}
void execute_cgi(int client, const char *path,
        const char *method, const char *query_string)
{
  
}
void not_found(int client)
{
    putline(client,"HTTP/1.0 404 NOT FOUND");
    putline(client, "Content-Type: text/html\r\n");
    putline(client, "<HTML><TITLE>Not Found</TITLE>");
    putline(client, "<BODY><P>The server could not fulfill");
    putline(client, "your request because the resource specified");
    putline(client, "is unavailable or nonexistent.");
    putline(client, "</BODY></HTML>");
}
void redirect(int client,char* re_path){
    char buf[200];
    getHttpReturn(302,buf);
    putline(client,buf);
    setLocation(buf,re_path);
    putline(client,buf);
    putline(client,"\r\n");
}

void path_handler(int client,char* path,char* method,char* qs){
    if(path ==NULL || method == NULL || qs == NULL){
        perror("NO Message");
        exit(1);
    }
    if(  strstr(method,"GET") != 0){
        char tp[20]="src/web";
        int len;
        len=strlen(path);
        if( len == 1){
            strcat(tp,"/index.html");
            char* cat=strtok(tp,"\r\n");
            send_html_file(client,cat);
        }else if( strstr(path,"/index") !=NULL ||  strstr(path,"/index.html") !=NULL && len>=5){
            char tp[20];
            strcat(tp,path);
            send_html_file(client,tp);
        }else {    
                FILE *fp;
                int c=0;
                if(strstr(path,".html") !=NULL);
                else strcat(path,".html");
                fp=fopen(path,"r");
                    if(fp == NULL){
                        c=1;
                   }
                pid_t pid=fork();
                if(pid == 0 && c==1){
                        send_html_file(client,"src/web/index.html");
                }else if (c == 0){
                    send_html_file(client,path);; 
                }

        }

    }else if(strstr(method,"POST") != 0){
        if(strlen(qs)  > 0){
           printf("直接接收到数据:%s\n",qs);
           memset(qs,'\0',sizeof(qs));
        }else{
            recv(client,qs,100,0);
            printf("再次传输数据:%s\n",qs);
        }
        
    }else if(strstr(method,"HEAD") != 0){
        Log("HEAD");
    }else{
        
    }
    close(client);

}
void accept_request(void *arg){
    client_info c_s;
    int client=(intptr_t)arg;
    char buf[1000];
    c_s.sock=client;
    setClient(&c_s);
    pid_t pid=fork();
    if(pid < 0) printf("error pid \n");
    if(pid == 0){
        path_handler( client,c_s.Path,c_s.Method,c_s.queryString);
        memset(c_s.queryString,'\0',sizeof(c_s.queryString));
    }
  //  send_html_file(client,"src/web/index.html");
    //redirect(client,"http://www.baidu.com");
}


