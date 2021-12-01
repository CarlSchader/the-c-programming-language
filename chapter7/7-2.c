#include<stdio.h>

#define LINECUTOFF 50

int main() {
    char c;
    int n;
    for (n = 0; (c = getchar()) != EOF; n++) {
        if (n >= LINECUTOFF) {
            putchar('\n');
            n = 0;
        }
        printf(c < 32 ? " 0x%.2X " : "%c", c);
    }

    return 0;
}