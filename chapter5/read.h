#if !defined(READ_H)
#define READ_H

#define MAXLINE 4096

int getLine(char *s, int lim);
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

#endif