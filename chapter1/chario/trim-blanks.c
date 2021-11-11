#include<stdio.h>

int main() {
    int c;
    int previous_blank = 0;

    while ((c = getchar()) != EOF) {
        if (c != ' ') {
            if (previous_blank) {
                putchar(' ');
                previous_blank = 0;
            }
            putchar(c);
        } else {
            previous_blank = 1;
        }
    }
}