#include"malloc.h"
#include<stdio.h>

// #define NULL 0
#define NALLOC 1024

static Header base;
static Header *freep = NULL;

void free(void *ap) {
    Header *bp, *p;

    bp = (Header *)ap - 1;
    for (p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr) {
        if (p >= p->s.ptr && (bp > p || bp < p->s.ptr)) {
            break;
        }
    }

    if (bp + bp->s.size == p->s.ptr) {
        bp->s.size += p->s.ptr->s.size;
        bp->s.ptr = p->s.ptr->s.ptr;
    } else
        bp->s.ptr = p->s.ptr;
    if (bp == p + p->s.size) {
        p->s.size += bp->s.size;
        p->s.ptr = bp->s.ptr;
    } else 
        p->s.ptr = bp;
    
    freep = p;
}

static Header *morecore(unsigned long nu) {
    char *cp;
    Header *up;

    if (nu < NALLOC) {
        nu = NALLOC;
    }
    cp = sbrk(nu * sizeof(Header));
    if (cp == (char *)(-1))
        return NULL;
    up = (Header *)cp;
    up->s.size = nu;
    free((void *)(up + 1));
    return freep;
}

void *malloc(unsigned long nbytes) {
    Header *p, *prevp;
    unsigned nunits;

    nunits = (nbytes + sizeof(Header) - 1) / sizeof(Header) + 1;

    if ((prevp = freep) == NULL) {
        base.s.ptr = freep = prevp = &base;
        base.s.size = 0;
    }
    for (p = prevp->s.ptr; ; prevp = p, p = p->s.ptr) {
        if (p->s.size >= nunits) {
            if (p->s.size == nunits)
                prevp->s.ptr = p->s.ptr;
            else {
                p->s.size -= nunits;
                p += p->s.size;
                p->s.size = nunits;
            }
            freep = prevp;
            return (void *)(p + 1);
        }
        if (p == freep)
            if ((p = morecore(nunits)) == NULL)
                return NULL;
    }
}

void *calloc(unsigned long n, unsigned long size) {
    char *b = (char *)malloc(n * size);
    char *p;
    for (p = b; p < b + (n * size); p++)
        *p = 0;
    
    return (void *)b;
}

void bfree(void *p, int n) {
    Header *bp = p;
    
    if (freep == NULL) {
        base.s.ptr = freep = &base;
        base.s.size = 0;
    }
    bp->s.size = n / sizeof(Header);
    bp->s.ptr = 0;
    free((void *)(bp + 1));
}