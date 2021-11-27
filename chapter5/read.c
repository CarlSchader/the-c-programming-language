#include"read.h"
#include"alloc.h"
#include<stdio.h>
#include<string.h>

int getLine(char *s, int lim) {
    int c, length, i;
    
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    
    if (c == EOF && i == 0)
        return -1;
    else {
        s[i] = '\0';
        return i;   
    }
}

int readlines(char *lineptr[], int nlines) {
    int linecount, linelen;
    char line[MAXLINE];

    for (linecount = 0; linecount < nlines && (linelen = getLine(line, MAXLINE)) != -1; ++linecount, ++lineptr) {
        *lineptr = alloc(linelen + 1);
        strcpy(*lineptr, line);
    }
    
    return linecount;
}

void writelines(char *lineptr[], int nlines) {
    for (; nlines > 0; --nlines, ++lineptr)
        printf("%s\n", *lineptr);
}