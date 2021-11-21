#include<stdio.h>

int invert(int x, int p, int n) {
    return x ^ (~(~0 << n) << (p + 1 - n));
}

int main() {
    int x = 0xaaaaaaaa;

    printf("%x\n", invert(x, 23, 16));
}