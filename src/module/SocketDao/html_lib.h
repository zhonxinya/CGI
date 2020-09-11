#ifndef _HTML_LIB_H
#define _HTML_LIB_H
#include<stdio.h>
void get_code(int code);
 int hexit( char c );
 void file_details( char* dir, char* name );
 char* get_mime_type( char* name );
 void strdecode( char* to, char* from );
 int hexit( char c );
 void strencode( char* to, size_t tosize, const char* from );
 void send_headers( int status, char* title, char* extra_header, char* mime_type, off_t length, time_t mod );
 void send_errors( int status, char* title, char* extra_header, char* text );
#endif