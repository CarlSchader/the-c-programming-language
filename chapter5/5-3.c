#include<stdio.h>

#define SIZE 1024

void stringcat(char *s, char *t) {
    for (; *s != '\0'; s++);
    for (; (*s = *t) != '\0'; s++, t++);
}

int main() {
    char s[SIZE] = "Hello, ";
    char t[SIZE] = "World!";
    stringcat(s, t);
    printf("%s\n", s);
}