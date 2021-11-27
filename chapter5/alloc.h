#if !defined(ALLOC_H)
#define ALLOC_H

#define ALLOCSIZE 1048576

char *alloc(int size);
void freep(char *p);

#endif