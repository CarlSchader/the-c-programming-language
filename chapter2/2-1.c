#include<stdio.h>
#include<limits.h>
#include<float.h>
#include<math.h>

int main() {
    printf("From headers:\n\n");

    printf("char: %d %d \n", SCHAR_MIN, SCHAR_MAX);
    printf("short: %d %d \n", SHRT_MIN, SHRT_MAX);
    printf("int: %d %d \n", INT_MIN, INT_MAX);
    printf("long: %ld %ld \n", LONG_MIN, LONG_MAX);
    printf("float: %.0f %1.0f\n", FLT_MIN, FLT_MAX);
    printf("double: %.0f %1.0f\n", DBL_MIN, DBL_MAX);
    printf("unsigned char: %d %u \n", 0, UCHAR_MAX);
    printf("unsigned short: %d %u \n", 0, USHRT_MAX);
    printf("unsigned int: %d %u \n", 0, UINT_MAX);
    printf("unsigned long: %d %lu \n", 0, ULONG_MAX);
    putchar('\n');

    printf("From computation:\n\n");

    printf("char: %.0f %.0f \n", -pow(2,7), pow(2, 7) - 1);
    printf("short: %.0f %.0f \n", -pow(2,15), pow(2, 15) - 1);
    printf("int: %.0f %.0f \n", -pow(2,31), pow(2, 31) - 1);
    printf("long: %.0f %.0f \n", -pow(2,63), pow(2, 63) - 1);
    printf("float: %.0f %1.0f\n", FLT_MIN, FLT_MAX);
    printf("double: %.0f %1.0f\n", DBL_MIN, DBL_MAX);
    printf("unsigned char: %d %.0f \n", 0, pow(2, 8));
    printf("unsigned short: %d %.0f \n", 0, pow(2, 16));
    printf("unsigned int: %d %.0f \n", 0, pow(2, 32));
    printf("unsigned long: %d %.0f \n", 0, pow(2, 64));
    putchar('\n');

}