#include<stdio.h>

#define LIM 1024

int main() {
    int i;
    int s[LIM];
    char c;

    for (i = 0; i < LIM - 1; i++) {
        if ((c = getchar()) == '\n') {
            break;
        } else if (c == EOF) {
            break;
        }
        s[i] = c;
        putchar(c);
    }
    putchar('\n');
}