#include<stdio.h>

int main() {
    int c;
    long count = 0;

    while((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            ++count;
        }
    }

    printf("Whitespace count: %ld", count);
}