#include<stdio.h>
#include<string.h>

void helper(char s[], int i, int j) {
    if (i >= j) {
        return;
    } else {
        char c = s[i];
        s[i] = s[j];
        s[j] = c;
        helper(s, i + 1, j - 1);
    }
}

void reverse(char s[]) {
    helper(s, 0, strlen(s) - 1);
}

int main() {
    char s[1024] = "testing";
    reverse(s);
    printf("%s\n", s);
}