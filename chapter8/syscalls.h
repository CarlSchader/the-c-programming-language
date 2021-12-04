#if !defined(SYSCALLS_H)
#define SYSCALLS_H

#define BUFFSIZE 1024

int read(int, char *, int);
int write(int, char *, int);
// int open(char *, int, int);
int close(int);
long lseek(int, long, int);

#endif
