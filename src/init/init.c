#include "init.h"
#include "sdata.h"
#include "socketdao.h"
#include "log.h"
#include "taskmanger.h"
#include <signal.h>
#include "api.h"

void init(){
    int ser=0;
    int client_sock=0;
    char buf[1024];
    u_short port =5500;
    ser=server(&port);
    struct sockaddr_in client_name;
    socklen_t  client_name_len = sizeof(client_name);
    pthread_t acccpet_threda_new; 
    while(1){
        client_sock = accept(ser,
                (struct sockaddr *)&client_name,
                &client_name_len);
        if (client_sock == -1) error("accept");
        if(pthread_create(&acccpet_threda_new , NULL, (void *)accept_request, (void *)(intptr_t)client_sock) != 0) error("pthread_create");
        pthread_join(acccpet_threda_new, NULL);
    }
}