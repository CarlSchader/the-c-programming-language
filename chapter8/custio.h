#if !defined(CUSTIO_H)
#define CUSTIO_H

#define NULL 0
#define EOF (-1)
#define BUFSIZ 1024
#define OPEN_MAX 20

typedef struct _iobuf {
    int cnt;
    char *ptr;
    char *base;
    struct {
        unsigned int _READ : 1;
        unsigned int _WRITE : 1;
        unsigned int _UNBUF : 1;
        unsigned int _EOF : 1;
        unsigned int _ERR : 1;
    } flag;
    int fd;
} FILE;
extern FILE _iob[OPEN_MAX];

#define stdin (&_iob[0])
#define stdout (&_iob[1])
#define stderr (&_iob[2])

FILE *fopen(const char *, const char *);
int fclose(FILE *);
int fflush(FILE *);
int fseek(FILE *, long, int);
int _fillbuf(FILE *);
int _flushbuf(int, FILE *);

#define feof(p) ((p)->flag._EOF)
#define ferror(p) ((p)->flag._ERR)
#define fileno(p) ((p)->fd)

#define getc(p) (--(p)->cnt >=0 ? (unsigned char) *(p)->ptr++ : _fillbuf(p))
#define putc(x,p) (--(p)->cnt >=0 ? *(p)->ptr++ = (x) : _flushbuf((x), p))

#define getchar() getc(stdin)
#define putchar(x) putc((x), stdout)

#endif
