#include<stdio.h>

#define TABSPACES 4

int main() {
    int c, spaces = 0;

    while((c = getchar()) != EOF) {
        if (c == ' ') {
            ++spaces;
            if (spaces == TABSPACES) {
                putchar('\t');
            }
        } else {
            while (spaces > 0) {
                putchar(' ');
                --spaces;
            }
            putchar(c);
        }
    }
}