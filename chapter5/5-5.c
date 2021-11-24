#include<stdio.h>

#define SIZE 1024

void stringcpy(char *s, char *t, int n) {
    for (; n > 0 && (*s = *t) != '\0'; s++, t++);

    if (*s != '\0') {
        *(++s) = '\0';
    }
}

void stringcat(char *s, char *t, int n) {
    for (; *s != '\0'; s++);
    for (; n > 0 && (*s = *t) != '\0'; s++, t++, n--);

    if (*s != '\0') {
        *(++s) = '\0';
    }
}

int stringcmp(char *s, char *t, int n) {
    for (; n > 0 && *s == *t && *s != '\0'; s++, t++, n--);

    if (n == 0)
        return 0;
    else
        return *s - *t;
}

int main() {
    char s[SIZE] = "Hello, ";
    char t[SIZE] = "World!";
    stringcat(s, t, 3);
    printf("%s\n", s);

    char z[SIZE] = "hola";
    stringcpy(s, z, 3);
    printf("%s\n", s);

    printf("%d\n", stringcmp("123", "123", 3));
    printf("%d\n", stringcmp("123", "124", 2));
    printf("%d\n", stringcmp("123", "789", 5));
}