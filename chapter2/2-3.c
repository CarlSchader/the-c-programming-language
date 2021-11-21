#include<stdio.h>

int htoi(char s[]) {
    int i;
    int x = 0;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            x = x * 16 + (s[i] - '0');
        } else if (s[i] >= 'a' && s[i] <= 'f') {
            x = x * 16 + (s[i] - 'a' + 10);
        } else if (s[i] >= 'A' && s[i] <= 'F') {
            x = x * 16 + (s[i] - 'A' + 10);
        } else {
            return -1;
        }
    }
    return x;
}

int main() {
    printf("%x\n", htoi("E0afbcD"));
}