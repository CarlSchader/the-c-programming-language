#include<stdio.h>
#include<string.h>
#include"malloc.h"

int main(int argc, char *argv[]) {
    char *s;
    char arr[1024];
    if (argc < 2)
        return -1;

    bfree(arr, 1024);
    s = (char *)malloc(*argv[1] - '0');
    
    strcpy(s, argv[2]);

    printf("%s\n", s);

    return 0;
}