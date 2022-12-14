/* See LICENSE.dwm file for copyright and license details. */
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "util.h"

void
die(const char *fmt, ...) {
	va_list ap;

	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);

	if (fmt[0] && fmt[strlen(fmt)-1] == ':') {
		fputc(' ', stderr);
		perror(NULL);
	} else {
		fputc('\n', stderr);
	}

	exit(1);
}

void *
ecalloc(size_t nmemb, size_t size)
{
	void *p;

	if (!(p = calloc(nmemb, size)))
		die("calloc:");
	return p;
}

// https://stackoverflow.com/questions/3201451/how-to-convert-a-c-string-into-its-escaped-version-in-c
char* escape(char* buffer) {
    int i,j;
    int l = strlen(buffer) + 1;
    char esc_char[]= { '\a','\b','\f','\n','\r','\t','\v','\\'};
    char essc_str[]= {  'a', 'b', 'f', 'n', 'r', 't', 'v','\\'};
    char* dest  =  (char*)calloc( l*2,sizeof(char));
    char* ptr=dest;
    for(i=0;i<l;i++){
        for(j=0; j< 8 ;j++){
            if( buffer[i]==esc_char[j] ){
                *ptr++ = '\\';
                *ptr++ = essc_str[j];
                break;
            }
        }
        if(j == 8 )
        *ptr++ = buffer[i];
    }
    *ptr='\0';
    return dest;
}
