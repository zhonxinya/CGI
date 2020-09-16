#include<string.h>
#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "html_lib.h"
#include <time.h>
#define SERVER_NAME "micro_httpd"
#define SERVER_URL "http://www.acme.com/software/micro_httpd/"
#define PROTOCOL "HTTP/1.1"
#define RFC1123FMT "%a, %d %b %Y %H:%M:%S GMT"

 void send_msg(char* buf,int fd){
     send( fd, buf, strlen(buf), 0 );  
}
 void send_errors( int status, char* title, char* extra_header, char* text )
    {
        send_headers( status, title, extra_header, "text/html", -1, -1 );
        (void) printf( "\
        <!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\" \"http://www.w3.org/TR/html4/loose.dtd\">\r\n\
        <html>\r\n\
        <head>\r\n\
        <meta http-equiv=\"Content-type\" content=\"text/html;charset=UTF-8\">\r\n\
        <title>%d %s</title>\r\n\
        </head>\r\n\
        <body bgcolor=\"#cc9999\">\r\n\
        <h4>%d %s</h4>\r\n", status, title, status, title );
        (void) printf( "%s\r\n", text );
        (void) printf( "\
        <hr>\r\n\
         <address><a href=\"%s\">%s</a></address>\r\n\
        </body>\r\n\
        </html>\r\n", SERVER_URL, SERVER_NAME );
        exit(1);
 }

 void send_headers( int status, char* title, char* extra_header, char* mime_type, off_t length, time_t mod )
    {
        time_t now;
        char timebuf[100];
        (void) printf( "%s %d %s\r\n", PROTOCOL, status, title );
        (void) printf( "Server: %s\r\n", SERVER_NAME );
        now = time( (time_t*) 0 );
        (void) strftime( timebuf, sizeof(timebuf), RFC1123FMT, gmtime( &now ) );
        (void) printf( "Date: %s\r\n", timebuf );
        if ( extra_header != (char*) 0 )
                (void) printf( "%s\r\n", extra_header );
        if ( mime_type != (char*) 0 )
                (void) printf( "Content-Type: %s\r\n", mime_type );
        if ( length >= 0 )
                (void) printf( "Content-Length: %lld\r\n", (long long) length );
        if ( mod != (time_t) -1 )
                {
                (void) strftime( timebuf, sizeof(timebuf), RFC1123FMT, gmtime( &mod ) );
                (void) printf( "Last-Modified: %s\r\n", timebuf );
                }
       // (void) printf( "Connection: close\r\n" );
        (void) printf( "\r\n\r\n" );
    }
 void file_details( char* dir, char* name )
    {
     char encoded_name[1000];
     char path[2000];
     struct stat sb;
     char timestr[16];
     strencode( encoded_name, sizeof(encoded_name), name );
     (void) snprintf( path, sizeof(path), "%s/%s", dir, name );
     if ( lstat( path, &sb ) < 0 )
	(void) printf( "<a href=\"%s\">%-32.32s</a>    ???\r\n", encoded_name, name );
     else
	{
	(void) strftime( timestr, sizeof(timestr), "%d%b%Y %H:%M", localtime( &sb.st_mtime ) );
	(void) printf( "<a href=\"%s\">%-32.32s</a>    %15s %14lld\r\n", encoded_name, name, timestr, (long long) sb.st_size );
	}
     }
 char* get_mime_type( char* name )
    {
        char* dot;
        dot = strrchr( name, '.' );
        if ( dot == (char*) 0 )
                return "text/plain; charset=UTF-8";
        if ( strcmp( dot, ".html" ) == 0 || strcmp( dot, ".htm" ) == 0 )
                return "text/html; charset=UTF-8";
        if ( strcmp( dot, ".xhtml" ) == 0 || strcmp( dot, ".xht" ) == 0 )
                return "application/xhtml+xml; charset=UTF-8";
        if ( strcmp( dot, ".jpg" ) == 0 || strcmp( dot, ".jpeg" ) == 0 )
                return "image/jpeg";
        if ( strcmp( dot, ".gif" ) == 0 )
                return "image/gif";
        if ( strcmp( dot, ".png" ) == 0 )
                return "image/png";
        if ( strcmp( dot, ".css" ) == 0 )
                return "text/css";
        if ( strcmp( dot, ".xml" ) == 0 || strcmp( dot, ".xsl" ) == 0 )
                return "text/xml; charset=UTF-8";
        if ( strcmp( dot, ".au" ) == 0 )
                return "audio/basic";
        if ( strcmp( dot, ".wav" ) == 0 )
                return "audio/wav";
        if ( strcmp( dot, ".avi" ) == 0 )
                return "video/x-msvideo";
        if ( strcmp( dot, ".mov" ) == 0 || strcmp( dot, ".qt" ) == 0 )
                return "video/quicktime";
        if ( strcmp( dot, ".mpeg" ) == 0 || strcmp( dot, ".mpe" ) == 0 )
                return "video/mpeg";
        if ( strcmp( dot, ".vrml" ) == 0 || strcmp( dot, ".wrl" ) == 0 )
                return "model/vrml";
        if ( strcmp( dot, ".midi" ) == 0 || strcmp( dot, ".mid" ) == 0 )
                return "audio/midi";
        if ( strcmp( dot, ".mp3" ) == 0 )
                return "audio/mpeg";
        if ( strcmp( dot, ".ogg" ) == 0 )
                return "application/ogg";
        if ( strcmp( dot, ".pac" ) == 0 )
                return "application/x-ns-proxy-autoconfig";
        return "text/plain; charset=UTF-8";
    }

 void strdecode( char* to, char* from )
    {
        for( ; *from != '\0'; ++to, ++from )
                {
                if ( from[0] == '%' && isxdigit( from[1] ) && isxdigit( from[2] ) )
                {
                *to = hexit( from[1] ) * 16 + hexit( from[2] );
                from += 2;
                }
                else
                *to = *from;
                }
        *to = '\0';
    }


 int hexit( char c )
    {
        if ( c >= '0' && c <= '9' )
                return c - '0';
        if ( c >= 'a' && c <= 'f' )
                return c - 'a' + 10;
        if ( c >= 'A' && c <= 'F' )
                return c - 'A' + 10;
        return 0;		/* shouldn't happen, we're guarded by isxdigit() */
    }

 void strencode( char* to, size_t tosize, const char* from )
    {
        int tolen;
        for ( tolen = 0; *from != '\0' && tolen + 4 < tosize; ++from )
                {
                if ( isalnum(*from) || strchr( "/_.-~", *from ) != (char*) 0 )
                {
                *to = *from;
                ++to;
                ++tolen;
                }
                else
                {
                (void) sprintf( to, "%%%02x", (int) *from & 0xff );
                to += 3;
                tolen += 3;
                }
                }
        *to = '\0';
    }
