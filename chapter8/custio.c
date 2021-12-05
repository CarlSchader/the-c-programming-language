#include"custio.h"
#include"syscalls.h"
#include<fcntl.h>
#include<stdlib.h>

#define PERMS 0666

FILE *fopen(const char *name, const char *mode) {
    int fd;
    FILE *fp;

    if (*mode != 'r' && *mode != 'w' && *mode != 'a')
        return NULL;
    for (fp = _iob; fp < _iob + OPEN_MAX; fp++)
        if (!(fp->flag._READ || fp->flag._WRITE))
            break;
    if (fp >= _iob + OPEN_MAX)
        return NULL;
    
    if (*mode == 'w')
        fd = creat(name, PERMS);
    else if (*mode == 'a') {
        if ((fd = open(name, O_WRONLY, 0)) == -1)
            fd = creat(name, PERMS);
        lseek(fd, 0l, 2);
    } else
        fd = open(name, O_RDONLY, 0);
    if (fd == -1)
        return NULL;

    fp->fd = fd;
    fp->cnt = 0;
    fp->base = NULL;
    fp->flag._UNBUF = 0;
    fp->flag._EOF = 0;
    fp->flag._ERR = 0;

    if (*mode == 'r') {
        fp->flag._READ = 1;
        fp->flag._WRITE = 0;
    } else {
        fp->flag._READ = 0;
        fp->flag._WRITE = 1;
    }

    return fp;
}

int _fillbuf(FILE *fp) {
    int bufsize;

    if (fp->flag._READ && (fp->flag._EOF || fp->flag._ERR))
        return EOF;
    bufsize = fp->flag._UNBUF ? 1 : BUFSIZ;
    if (fp->base == NULL)
        if ((fp->base = (char *) malloc(bufsize)) == NULL)
            return EOF;
    fp->ptr = fp->base;
    fp->cnt = read(fp->fd, fp->ptr, bufsize);
    if (--(fp->cnt) < 0) {
        if (fp->cnt == -1)
            fp->flag._EOF = 1;
        else
            fp->flag._ERR = 1;
        fp->cnt = 0;
        return EOF;
    }
    return (unsigned char) *fp->ptr++;
}

int _flushbuf(int x, FILE *fp) {
    int bufsize;
    if (!fp->flag._WRITE || fp->flag._ERR) {
        return EOF;
    }
    bufsize = fp->flag._UNBUF ? 1 : BUFSIZ;

    if (fp->base == NULL) {
        if ((fp->base = (char *) malloc(bufsize)) == NULL) {
            fp->flag._ERR = 1;
            return EOF;
        }
        fp->ptr = fp->base;
        fp->cnt = bufsize;
        write(fp->fd, (char *)&x, 1);
        return x;
    }

    *(fp->ptr++) = x;
    if (write(fp->fd, fp->base, bufsize - fp->cnt) != bufsize - fp->cnt) {
        fp->flag._ERR = 1;
        return EOF;
    }

    fp->cnt = bufsize;
    fp->ptr = fp->base;
        
    return x;
}

int fflush(FILE *fp) {
    if (_flushbuf('\0', fp) == EOF)
        return EOF;
    return 0;
}

int fclose(FILE *fp) {
    if (fp->base != NULL) {
        if (fp->flag._WRITE && _flushbuf('\0', fp) == EOF) {
            return EOF;   
        }
        free(fp->base);
    }
    fp->flag._READ = 0;
    fp->flag._WRITE = 0;
    return close(fp->fd);
}

int fseek(FILE *fp, long offset, int origin) {
    if (lseek(fp->fd, offset, origin) == -1)
        return -1;
    
    if (fp->flag._READ) {
        if (origin == 1) {
            fp->ptr += offset;
            fp->cnt -= offset;
        } else {
            fp->ptr = fp->base;
            fp->cnt = 0;
        }
    }

    return 0;
}

FILE _iob[OPEN_MAX] = {
    { 0, (char *) 0, (char *) 0, {1, 0, 0, 0, 0}, 0 },
    { 0, (char *) 0, (char *) 0, {0, 1, 0, 0, 0}, 1 },
    { 0, (char *) 0, (char *) 0, {0, 1, 1, 0, 0}, 2 },
};
