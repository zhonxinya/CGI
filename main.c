// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <errno.h>
// #include <string.h>
// #include <sys/types.h>
// #include <sys/socket.h>
// #include <netinet/in.h>
// #include <netdb.h>
// #include <arpa/inet.h>
// #include <sys/wait.h>
// #include <signal.h>
// #include "jsonrpc-c.h"
// #include "cJSON.h"
// #define PORT 1234  // the port users will be connecting to

// struct jrpc_server my_server;
// cJSON * say_hello(jrpc_context * ctx, cJSON * params, cJSON *id) {
// 	return cJSON_CreateString("Hello!");
// }
// cJSON * add(jrpc_context * ctx, cJSON * params, cJSON *id) {
// 	cJSON * a = cJSON_GetArrayItem(params,0);
// 	cJSON * b = cJSON_GetArrayItem(params,1);
// 	return cJSON_CreateNumber(a->valueint + b->valueint);
// }

// cJSON * exit_server(jrpc_context * ctx, cJSON * params, cJSON *id) {
// 	jrpc_server_stop(&my_server);
// 	return cJSON_CreateString("Bye!");
// }
// void printJson(cJSON * root)//以递归的方式打印json的最内层键值对
// {
//     for(int i=0; i<cJSON_GetArraySize(root); i++)   //遍历最外层json键值对
//     {
//         cJSON * item = cJSON_GetArrayItem(root, i);        
//         if(cJSON_Object == item->type)      //如果对应键的值仍为cJSON_Object就递归调用printJson
//             printJson(item);
//         else                                //值不为json对象就直接打印出键和值
//         {
//             printf("%s->", item->string);
//             printf("%s\n", cJSON_Print(item));
//         }
//     }
// }
// int main(void) {
//     cJSON * root =  cJSON_CreateObject();
//     cJSON * item =  cJSON_CreateObject();
//     cJSON * next =  cJSON_CreateObject();
//     cJSON_AddItemToObject(root, "rc", cJSON_CreateNumber(0));//根节点下添加
//     cJSON_AddItemToObject(root, "operation", cJSON_CreateString("CALL"));
//     cJSON_AddItemToObject(root, "service", cJSON_CreateString("telephone"));
//     cJSON_AddItemToObject(root, "text", cJSON_CreateString("打电话给张三"));
//     cJSON_AddItemToObject(root, "semantic", item);//root节点下添加semantic节点
//     cJSON_AddItemToObject(item, "slots", next);//semantic节点下添加item节点
//     cJSON_AddItemToObject(next, "name", cJSON_CreateString("李四"));//添加name节点

//     printf("%s\n", cJSON_Print(root));
// 	return 0;
//}/

#include<stdlib.h>
#include "sdata.h"
#include<string.h>
#include "init.h"
#include "sqlite3.h"
#include "html_lib.h"
int main()
{
	 init();
  // char enable[12]={0};
  // char des[12]={0};
  // int proto_in=0;
  // int proto_tri=0;
  // char port_s[12]={0};
  // char port_st[12]={0};
  // char port_et[12]={0};
  // char port_e[12]={0};
  // int wan_id=0;
  // char  str[128]="1-dd-1-12-13-1-12-13-2-";
  // sscanf(str,"%[^-]-%[^-]-%d-%[^-]-%[^-]-%d-%[^-]-%[^-]-%d-"
  //   ,enable,des,&proto_in,
  //   port_s,port_e,&proto_tri,
  //   port_st,port_et,&wan_id );
  //   printf("%s %s %d %s %s %d %s %s %d\n",enable,des,proto_in,port_s,port_e,proto_tri,port_st,port_et,wan_id );
  




    //  sqlite3 *db=NULL;
    //  int len;
    //  int i=0;
    //  int nrow=0;
    //  int ncolumn = 0;
    //  char *zErrMsg =NULL;
    //  char **azResult=NULL; //二维数组存放结果
    //  /* 打开数据库 */
    //  len = sqlite3_open("12",&db);
    //  if( len )
    //  {
    //     /*  fprintf函数格式化输出错误信息到指定的stderr文件流中  */
    //     fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));//sqlite3_errmsg(db)用以获得数据库打开错误码的英文描述。
    //     sqlite3_close(db);
    //     exit(1);
    //  }
    //  else printf("You have opened a sqlite3 database named user successfully!\n");
    //  /* 创建表 */
    //  char *sql = " CREATE TABLE SensorData(\
    //      ID INTEDER PRIMARY KEY,\
    //      SensorID INTEGER,\
    //      siteNum INTEGER,\
    //      Time VARCHAR(12),\
    //      SensorParameter REAL\
    //      );" ;
 
    //   sqlite3_exec(db,sql,NULL,NULL,&zErrMsg);
    //   char*sql1 ="INSERT INTO 'SensorData'VALUES(NULL,1,2,201430506201,13.5);";
    //   sqlite3_exec(db,sql1,NULL,NULL,&zErrMsg);
    //   char*sql2 ="INSERT INTO 'SensorData'VALUES(NULL,3,4,201530506302,14.5);";
    //   sqlite3_exec(db,sql2,NULL,NULL,&zErrMsg);
    //   char*sql3 ="INSERT INTO 'SensorData'VALUES(NULL,5,6,201630506413,18.6);";
    //   sqlite3_exec(db,sql3,NULL,NULL,&zErrMsg);
    //   sql="select *from SensorData";
    //   sqlite3_get_table( db , sql , &azResult , &nrow , &ncolumn , &zErrMsg );
    //   printf("nrow=%d ncolumn=%d\n",nrow,ncolumn);
    //   printf("the result is:\n");
    //   for(i=0;i<(nrow+1)*ncolumn;i++)
    //     {
    //       printf("azResult[%d]=%s\n",i,azResult[i]);
    //     }
    //   sql="delete from SensorData where SensorID = 1 ;";
    //   sqlite3_exec( db , sql , NULL , NULL , &zErrMsg );
    //   sql = "SELECT * FROM SensorData ";
    //   sqlite3_get_table( db , sql , &azResult , &nrow , &ncolumn , &zErrMsg );
    //   printf( "row:%d column=%d\n " , nrow , ncolumn );
    //   printf( "After deleting , the result is : \n" );
    //   for( i=0 ; i<( nrow + 1 ) * ncolumn ; i++ )
    //   {
    //         printf( "azResult[%d] = %s\n", i , azResult[i] );
    //   }
    //   sqlite3_free_table(azResult);
    //   sqlite3_close(db);
      return 0;
}

