#include<stdio.h>

#define TABSPACES 4

int main() {
    int c;
    int i;
    while((c = getchar()) != EOF) {
        if (c == '\t') {
            for (i = 0; i < TABSPACES; i++) {
                putchar(' ');
            }
        } else {
            putchar(c);
        }
    }
}