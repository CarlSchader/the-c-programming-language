#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[]) {
    int tabspaces = 4;
    int startcol = 0;

    for (++argv; argc > 1; argc--, argv++) {
        switch ((*argv)[0]) {
            case '-':
                if (strlen(*argv) > 1) {
                    startcol = atoi(&(*argv)[1]);
                }
                break;
            case '+':
                if (strlen(*argv) > 1) {
                    tabspaces = atoi(&(*argv)[1]);
                }
                break;
        }
    }


    int c;
    int i;
    while((c = getchar()) != EOF) {
        if (startcol <= 0) {
            if (c == '\t') {
                for (i = 0; i < tabspaces; i++) {
                    putchar(' ');
                }
            } else {
                putchar(c);
            }
        } else {
            putchar(c);
            startcol--;
        }
    }
}