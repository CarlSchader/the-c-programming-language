#include<stdio.h>

#define ASCIILENGTH 128

void printHist(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%c: ", i);
        for(int j = 0; j < arr[i]; j++) {
            putchar('X');
        }
        putchar('\n');
    }
}

int main() {
    int c, i;
    int chars[ASCIILENGTH];

    i = 0;

    for (i = 0; i < ASCIILENGTH; i++) {
        chars[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        ++chars[c];
    }

    printHist(chars, ASCIILENGTH);
}