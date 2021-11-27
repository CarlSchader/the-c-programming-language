#include"read.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

#define MAXLINES 1024

char *lineptr[MAXLINES];

int stringcomp(const void *a, const void* b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int reversestringcomp(const void *a, const void* b) {
    return strcmp(*(const char **)b, *(const char **)a);
}

int foldcase(const void *a, const void *b) {
    return 0;
}

int numericcomp(const void *a, const void *b) {
    return atof(*(const char **)a) - atof(*(const char **)b) < 0.0 ? -1 : 1;
}

int reversenumericcomp(const void *a, const void *b) {
    return atof(*(const char **)b) - atof(*(const char **)a) < 0.0 ? -1 : 1;
}

int main(int argc, char *argv[]) {
    int numeric, reverse;
    numeric = reverse = 0;

    for (++argv ;argc > 1; --argc, ++argv) {
        if (strcmp(*argv, "-n") == 0)
            numeric = 1;
        if (strcmp(*argv, "-r") == 0)
            reverse = 1;
    }

    int nlines = readlines(lineptr, MAXLINES);

    if (numeric) {
        if (reverse) {
            qsort(lineptr, nlines, sizeof(char *), reversenumericcomp);
        } else {
            qsort(lineptr, nlines, sizeof(char *), numericcomp);
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