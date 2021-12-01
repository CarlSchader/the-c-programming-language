#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main(int argc, char *argv[]) {
    int upperprog = 0;

    if (strstr(argv[0], "upper")) {
        upperprog = 1;
    }

    for (char c; (c = getchar()) != EOF;)
        putchar(upperprog ? toupper(c) : tolower(c));

    return 0;
}