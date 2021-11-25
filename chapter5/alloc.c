#include"alloc.h"
#include<stdio.h>

#define ALLOCSIZE 4096

static char buff[ALLOCSIZE];
static char *bp = buff;

char *alloc(int size) {
    if (buff + ALLOCSIZE - bp >= size) {
        bp += size;
        return bp - size;
    } else {
        return 0;
    }
}

void freep(char *p) {
    if (p >= buff && p <= buff + ALLOCSIZE)
        bp = p;
}