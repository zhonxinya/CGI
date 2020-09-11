#ifndef _LOG_H_
#define _LOG_H_
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <errno.h>
#define filename(x) strrchr(x,'/')?strrchr(x,'/')+1:x

#define  Log(...) {                                                     \
                printf("\n\033[31mTime:%s %s File: %s   Function: %s   Line: %d  Tips: %s"  "  Output: %s\033[0m\n" \
                ,__TIME__,__DATE__,filename(__FILE__), __FUNCTION__,__LINE__,__VA_ARGS__,strerror(errno) );    \
                                                                             \
}

#define  error(...) {                                                     \
                printf("\n\033[31mTime:%s %s File: %s   Function: %s   Line: %d  Tips: %s  Output: %s\033[0m\n" \
                ,__TIME__,__DATE__,filename(__FILE__), __FUNCTION__,__LINE__,__VA_ARGS__,strerror(errno) );    \
                exit(0)          ;                                                   \
}
#endif

