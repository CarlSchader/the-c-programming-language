#include<stdio.h>
#include<limits.h>

int rightrot(int x, int n) {
    int b = 0;
    int s = ~0;

    while (s != 0) {
        s = s << 1;
        ++b;
    }

    int y = ~(~0 << n) & x;
    y = y << (b - n);
    x = x >> n;
    return x | y;
}

int main() {
    int x = 0xffff;

    printf("%x\n", rightrot(x, 24));
}