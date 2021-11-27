#include"read.h"
#include"alloc.h"
#include<stdio.h>
#include<string.h>

#define MAXLINE 4096

int getLine(char *s, int lim) {
    int c, length, i;
    
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF; i++) {
        if (c == '\n') {
            break;
        } else {
            s[i] = c;
        }
    }

    s[i] = '\0';
    return i;
}

int readlines(char *lineptr[], int nlines) {
    int linecount, linelen;
    char line[MAXLINE];

    for (linecount = 0; linecount < nlines && (linelen = getLine(line, MAXLINE)) > 0; ++linecount, ++lineptr) {
        *lineptr = alloc(linelen + 1);
        strcpy(*lineptr, line);
    }
    
    return linecount;
}

void writelines(char *lineptr[], int nlines) {
    for (; nlines > 0; --nlines, ++lineptr)
        printf("%s\n", *lineptr);
}