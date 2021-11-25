#include<stdio.h>
#include<stdlib.h>

#define DEFAULTSPACES 4

int main(int argc, char *argv[]) {
    int tabspaces = DEFAULTSPACES;
    if (argc > 1)
        tabspaces = atoi(++argv);
    int c;
    int i;
    while((c = getchar()) != EOF) {
        if (c == '\t') {
            for (i = 0; i < tabspaces; i++) {
                putchar(' ');
            }
        } else {
            putchar(c);
        }
    }
}