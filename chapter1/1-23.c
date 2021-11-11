#include<stdio.h>

#define MAXLINE 1024

int getLine(char s[], int lim);

int main() {
    int squote = 0;
    int dquote = 0;
    int slash = 0;
    int comment = 0;
    int c;

    char buff[MAXLINE];

    while ((c = getchar()) != EOF) {
        if (squote && c == '\'') {
            putchar(c);
            squote = 0;
        } else if (dquote && c == '\"') {
            putchar(c);
            dquote = 0;
        } else if (!squote && !dquote && slash) {
            if (c == '/') {
                getLine(buff, MAXLINE);
            } else if (c == '*') {
                comment = 1;
            } else {
                putchar('/');
                putchar(c);
            }
            slash = 0;
        } else if (!squote && !dquote && comment == 1) {
            if (c == '*') {
                comment = 2;
            }
        } else if (!squote && !dquote && comment == 2) {
            if (c == '/') {
                comment = 0;
            } else {
                comment = 1;
                putchar('*');
                putchar(c);
            }
        } else {
            if (c == '\'') {
                putchar(c);
                squote = 1;
            } else if (c == '\"') {
                putchar(c);
                dquote = 1;
            } else if (!squote && !dquote && c == '/') {
                slash = 1;
            } else {
                putchar(c);
            }
        }
    }
}

int getLine(char s[], int lim) {
    int c, length, i;
    
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF; i++) {
        s[i] = c;
        
        if (c == '\n') {
            ++i;
            break;
        }
    }

    s[i] = '\0';
    return i;
}
