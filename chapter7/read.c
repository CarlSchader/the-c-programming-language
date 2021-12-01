#include"read.h"
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define MAXBUFF 1024

static int buff[MAXBUFF];
static int *bp = buff;
int currentline = 1;

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
        *lineptr = (char *)malloc(linelen + 1);
        strcpy(*lineptr, line);
    }
    
    return linecount;
}

void writelines(char *lineptr[], int nlines) {
    for (; nlines > 0; --nlines, ++lineptr)
        printf("%s\n", *lineptr);
}

int getch() {
    int next = bp - buff > 0 ? *(--bp) : getchar();
    if (next == '\n')
        currentline++;

    return next;
}

void ungetch(int c) {
    if (bp - buff >= MAXBUFF)
        printf("error: ungetch buffer full\n");
    else {
        if (c == '\n')
            currentline--;
        *bp = c;
        ++bp;
    }
}

void clearbuff() {
    bp = buff;
}

int getword(char *word, int lim) {
    int c;
    char *w = word;

    while (isspace(c = getch()));

    if (c != EOF)
        *w++ = c;
    else
        return EOF;

    for (; lim-- > 0; w++) {
        if ((*w = getch()) == ' ' || *w == '\t' || *w == '\n' || *w == EOF) {
            ungetch(*w);
            break;
        }
    }

    *w = '\0';
    return word[0];
}

int gettoken(char *word, int lim) {
    int c;
    char *w = word;

    while (isspace(c = getch()));

    if (c != EOF)
        *w++ = c;
    if (!isalnum(c)) {
        *w = '\0';
        return c;
    }

    for (; --lim > 0; w++) {
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    }

    *w = '\0';
    return word[0];
}