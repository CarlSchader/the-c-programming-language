#include<stdio.h>

int setbits(int x, int p, int n, int y) {
    x = x & (~0 << n);
    return x | (y >> (p + 1 - n)) & ~(~0 << n); 
}

int main() {
    int y = 0xabab;
    int x = 0xcdcdefef;

    printf("%x\n", setbits(x, 23, 16, y));
}