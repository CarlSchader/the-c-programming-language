#include"read.h"
#include"alloc.h"
#include<stdio.h>
#include<string.h>

#define MAXBUFF 1024

static int buff[MAXBUFF];
static int *bp = buff;

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

int getch() {
    return bp - buff > 0 ? *(--bp) : getchar();
}

void ungetch(int c) {
    if (bp - buff >= MAXBUFF)
        printf("error: ungetch buffer full\n");
    else {
        *bp = c;
        ++bp;
    }
}

void clearbuff() {
    bp = buff;
}