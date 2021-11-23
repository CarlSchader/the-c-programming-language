#include<stdio.h>

#define swap(t, x, y) (t)y, (t)x

int main() {
    printf("%d %d\n", swap(int, 10, 12));
}