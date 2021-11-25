#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"alloc.h"

#define MAXSTORED 1024
#define MAXLINE 1024

int getLine(char *buffer, int size) {
    int count;
    for (count = 0; size > 0 && (*buffer = getchar()) != '\n' && *buffer != EOF; size--, buffer++)
        count++;

    if (*buffer == EOF) {
        *buffer = '\0';
        return -1;
    } else {
        *buffer = '\0';
        return count;
    }
}

int main(int argc, char *argv[]) {
    char *storedlines[MAXSTORED];
    int lines = 10;
    char line[MAXLINE];

    for (++argv; argc > 1; --argc, ++argv) {
        switch ((*argv)[0]) {
            case '-':
                if (strlen(*argv) > 1) {
                    lines = atoi(&(*argv)[1]);
                }
                break;
        }
    }
    
    int i, linesize;
    for (i = 0; i < MAXSTORED && (linesize = getLine(line, MAXLINE)) != -1; i++) {
        storedlines[i % lines] = alloc(linesize + 1);
        strcpy(storedlines[i % lines], line);
    }
    storedlines[i % lines] = alloc(linesize + 1);
    strcpy(storedlines[i % lines], line);
    
    int j;
    for (j = i < lines - 1 ? i : lines - 1; j >= 0; j--) {
        printf("%s\n", storedlines[(i - j) % lines]);
    }
}