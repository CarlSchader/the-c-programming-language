#include<stdio.h>

int stringlen(char s[]) {
    int i;
    for (i = 0; s[i] != '\0'; i++)
        ;
    return i;
}

void reverse(char s[]) {
    int i, j;
    char c;
    for (i = 0, j = stringlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itob(int n, char s[], int b) {
    int mod;
    int i = 0;
    int sign = 1;

    if (n < 0) {
        sign = -1;
        n = -n;
    }

    while (n != 0) {
        mod = n % b;
        if (mod > 9) {
            s[i++] = 'a' + (char)(mod - 10);
        } else {
            s[i++] = '0' + (char)mod;
        }
        n /= b;
    }

    if (sign < 0) {
        s[i++] = '-';
    }
    s[i++] = '\0';
    reverse(s);
}

int main() {
    int n = 1024;
    char s[1024];

    itob(n, s, 16);
    printf("%s\n", s);
}