#include<stdio.h>

int binsearch(int a[], int n, int x) {
    int low, mid, high;
    low = 0;
    high = n - 1;

    while (low < high) {
        mid = (low + high) / 2;
        if (x < a[mid]) {
            high = mid - 1;
        } else {
            low = mid;
        }
    }

    return x == a[low] ? low : -1;
}

int main() {
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    printf("%d\n", binsearch(a, 10, 7));
}