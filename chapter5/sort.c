#include"read.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

#define MAXLINES 1024

char *lineptr[MAXLINES];

void lower(char *s) {
    int diff = 'A' - 'a';
    for (; *s != '\0'; ++s) {
        if (*s >= 'A' && *s <= 'Z') {
            *s = diff < 0 ? *s - diff : *s + diff;
        }
    }
}

int stringcomp(const void *a, const void* b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int reversestringcomp(const void *a, const void* b) {
    return strcmp(*(const char **)b, *(const char **)a);
}

int foldcase(const void *a, const void *b) {
    const char *x = *(const char **)a;
    const char *y = *(const char **)b;
    for (; *x != '\0'; ++x, ++y) {
        
    }

    return strcmp(x, y);
}

int reversefoldcase(const void *a, const void *b) {
    char *x = *(char **)a;
    char *y = *(char **)b;
    lower(x);
    lower(y);

    return strcmp(y, x);
}

int numericcomp(const void *a, const void *b) {
    return atof(*(const char **)a) - atof(*(const char **)b) < 0.0 ? -1 : 1;
}

int reversenumericcomp(const void *a, const void *b) {
    return atof(*(const char **)b) - atof(*(const char **)a) < 0.0 ? -1 : 1;
}

int main(int argc, char *argv[]) {
    int numeric, reverse, fold;
    numeric = reverse = fold = 0;

    for (++argv ;argc > 1; --argc, ++argv) {
        if (strcmp(*argv, "-n") == 0)
            numeric = 1;
        if (strcmp(*argv, "-r") == 0)
            reverse = 1;
        if (strcmp(*argv, "-f") == 0)
            fold = 1;
    }

    int nlines = readlines(lineptr, MAXLINES);

    if (numeric) {
        if (reverse) {
            qsort(lineptr, nlines, sizeof(char *), reversenumericcomp);
        } else {
            qsort(lineptr, nlines, sizeof(char *), numericcomp);
        }
    } else if (fold) {
        if (reverse) {
            qsort(lineptr, nlines, sizeof(char *), reversefoldcase);
        } else {
            qsort(lineptr, nlines, sizeof(char *), foldcase);
        }
    } else {
        if (reverse) {
            qsort(lineptr, nlines, sizeof(char *), reversestringcomp);
        } else {
            qsort(lineptr, nlines, sizeof(char *), stringcomp);
        }
    }

    writelines(lineptr, nlines);
}