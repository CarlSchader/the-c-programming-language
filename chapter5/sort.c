#include"read.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>

#define MAXLINES 1024
#define MAPSIZE 256

int numeric, reverse, fold, fieldstart, fieldoffset;

char cmpmap[MAPSIZE] = { 0 };

void lower(char *s) {
    int diff = 'A' - 'a';
    for (; *s != '\0'; ++s) {
        if (*s >= 'A' && *s <= 'Z') {
            *s = diff < 0 ? *s - diff : *s + diff;
        }
    }
}

void removechars(char *s, char* set) {
    char *p;
    for (p = s; *s != '\0'; ++s) {
        if (!(*(set + (int)*s))) {
            *p = *s;
            ++p;
        }
    }
    *p = '\0';
} 

void reversearray(char *lineptr[], int size) {
    char *temp;
    char **endp;
    for (endp = lineptr + size - 1; endp - lineptr > 0; --endp, ++lineptr) {
        temp = *lineptr;
        *lineptr = *endp;
        *endp = temp;
    }
}

int stringcomp(const void *a, const void* b) {
    char x[MAXLINE], y[MAXLINE];

    strcpy(x, *(const char **)a + fieldstart), strcpy(y, *(const char **)b + fieldstart);
    
    if (fieldoffset > 0)
        *(y + fieldoffset) = *(x + fieldoffset) = '\0';
    
    removechars(x, cmpmap);
    removechars(y, cmpmap);

    if (fold)
        lower(x), lower(y);

    return (numeric ? (atof(*(const char **)a) - atof(*(const char **)b) < 0.0 ? -1 : 1) : strcmp(x, y)) * (reverse ? -1 : 1);
}

int main(int argc, char *argv[]) {
    char *lineptr[MAXLINES];
    numeric = reverse = fold = fieldstart = 0;
    fieldoffset = -1;

    for (++argv ;argc > 1; --argc, ++argv) {
        if (**argv == '-') {
            for (char *c = *argv; *c != '\0'; ++c) {
                char *val;
                switch (*c) {
                    case 'n':
                        numeric = 1;
                        break;
                    case 'r':
                        reverse = 1;
                        break;
                    case 'f':
                        fold = 1;
                        break;
                    case 'd':
                        for (int i = 0; i < MAPSIZE; ++i) {
                            if (!(
                                (i >= 'a' && i <= 'z') ||
                                (i >= 'A' && i <= 'Z') ||
                                (i >= '0' && i <= '9') ||
                                (i == ' ' || i == '\n' || i == '\t')
                                )) {
                                    cmpmap[i] = 1;
                            }
                        }
                        break;
                    case 's':
                        val = *(argv + 1);
                        fieldstart = atoi(val);
                        break;
                    case 'o':
                        val = *(argv + 1);
                        fieldoffset = atoi(val);
                        break;
                }
            }
        }
    }

    int nlines = readlines(lineptr, MAXLINES);

    qsort(lineptr, nlines, sizeof(char *), stringcomp);

    writelines(lineptr, nlines);
}