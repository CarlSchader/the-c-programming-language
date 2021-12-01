#include<stdarg.h>
#include<stdio.h>
// #include"read.h"

void minprintf(char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    for (; *fmt != '\0'; fmt++) {
        if (*fmt != '%') {
            putchar(*fmt);
        } else {
            switch (*(++fmt)) {
                case 'd':
                    printf("%d", va_arg(ap, int));
                    break;
                case 'f':
                    printf("%f", va_arg(ap, double));
                    break;
                case 's':
                    printf("%s", va_arg(ap, char *));
                    break;
                case 'x':
                    printf("%x", va_arg(ap, int));
                    break;
                case 'X':
                    printf("%X", va_arg(ap, int));
                    break;
                default:
                    putchar(*fmt);
                    break;
            }
        }
    }
    va_end(ap);
}

int main() {
    minprintf("%d %f %s %x %X\n", 1024, 10.5, "hello", 255, 127);
    
    return 0;
}