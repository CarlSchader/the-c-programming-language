#include<string.h>
#include<stdio.h>

int strrindex(char s[], char search[]) {
    int i, j;
    int searchlen = strlen(search) - 1;
    for (i = strlen(s) - 1, j = searchlen - 1; i >= 0; i--) {
        if (s[i] == search[j]) {
            if (j == 0) {
                return i;
            } else {
                j--;
            }
        } else {
            j = searchlen - 1;
        }
    }

    return -1;
}

int main() {
    printf("%d\n", strrindex("Hello, my name is Carl!", "Carl"));
}