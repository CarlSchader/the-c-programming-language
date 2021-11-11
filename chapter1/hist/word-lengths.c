#include<stdio.h>

#define IN 1
#define OUT 0
#define LENGTHMAX 45

void printHist(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%4.0f: ", i + 1.0);
        for(int j = 0; j < arr[i]; j++) {
            putchar('X');
        }
        putchar('\n');
    }
}

int main() {
    int c, state, wlength, i;
    int lengths[LENGTHMAX];

    state = OUT;
    wlength = 0;

    for (i = 0; i < LENGTHMAX; i++) {
        lengths[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (state == IN) {
                ++lengths[wlength - 1];
                state = OUT;
                wlength = 0;
            }
        } else {
            if (state == OUT) {
                state = IN;
            }
            ++wlength;
        }
    }

    printHist(lengths, LENGTHMAX);
}