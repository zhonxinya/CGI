#ifndef _SDATA_H_
#define _SDATA_H
#include "list.h"
#include <stddef.h>

typedef struct 
{
    char key[128];
    char value[128];
}JSON;

typedef struct 
{
    JSON  json;
    struct list_head  list;
}Msg ;




#endif