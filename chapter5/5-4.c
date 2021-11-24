#include<stdio.h>
#include<string.h>

#define SIZE 1024

int stringend(char *s, char *t) {
    for (; *s != '\0'; s++);
    
    char *z = t;
    for (; *z != '\0'; z++);
    
    for (; z >= t; s--, z--) {
        if (*z != *s)
            return 0;
    }
    
    return 1;
}

int main() {
    char s[SIZE] = "Hello, World!";
    char t[SIZE] = "World!";
    printf("%d\n", stringend(s, t));
}