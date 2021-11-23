#include<stdio.h>
#include<ctype.h>

#define MAXBUF 1024

char buff[MAXBUF];
int bp = 0;

int getch() {
    int temp;
    if (bp > 0) {
        return buff[--bp];
    } else {
        return getchar();
    }
}

void ungetch(int c) {
    if (bp >= MAXBUF) {
        printf("error: ungetch buffer full\n");
    } else {
        buff[bp++] = c;
    }
}

int getfloat(float *pn) {
    int c, sign;

    while (isspace(c = getch()))
        ;
    
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        c = getch();
        if (c != '.' && !isdigit(c)) {
            ungetch(c);
            ungetch('+');
            return 0;
        }
    }

    for (*pn = 0; isdigit(c); c = getch()) 
        *pn = 10.0 * *pn + (float)(c - '0');
    
    
    float pow = 1.0;

    if (c == '.') {
        c = getch();
        for (; isdigit(c); c = getch()) {
            *pn = 10.0 * *pn + (float)(c - '0');
            pow *= 10.0;
        }
    }

    *pn = (sign * *pn) / pow;

    if (c != EOF)
        ungetch(c);
    
    return c;
}

int main() {
    float x;
    if (getfloat(&x)) {
        printf("float: %.3g\n", x);
    } else {
        printf("nan\n");
    }
}