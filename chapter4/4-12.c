#include<stdio.h>

int helper(int x, char s[], int i, int offset) {
    if (x == 0) {
        s[i + offset] = '\0';
        return i - 1;
    }
    
    int j = helper(x / 10, s, i + 1, offset);
    s[j - i + offset] = '0' + (x % 10);
    return j;
}

void itoa(int x, char s[]) {
    if (x < 0) {
        s[0] = '-';
        helper(-x, s, 0, 1);
    } else {
        helper(x, s, 0, 0);
    }
}

int main() {
    char s[1024];
    itoa(1024, s);
    printf("%s\n", s);
}