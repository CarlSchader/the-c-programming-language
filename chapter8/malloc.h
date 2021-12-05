#ifndef MALLOC_H
#define MALLOC_H

#undef malloc

typedef long Align;

union header {
    struct {
        union header *ptr;
        unsigned size;
    } s;
    Align x;
};

typedef union header Header;

char *sbrk(int);

void free(void *);
void bfree(void *, int);
static Header *morecore(unsigned long);
void *malloc(unsigned long);
void *calloc(unsigned long, unsigned long);

#endif