#include<stdarg.h>
#include<stdio.h>
#include<ctype.h>


int minscanf(char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    char c;
    int n;
    char word[1024];

    for (n = 0; *fmt != '\0'; fmt++) {
        while (isspace(*fmt))
            fmt++;
        
        if (*fmt == '%') {
            switch (*(++fmt)) {
                case 'd':
                    if (scanf("%d", va_arg(ap, int *)) == 0) {
                        va_end(ap);
                        return n;
                    }
                    else
                        n++;
                    break;
                case 'f':
                    if (scanf("%f", va_arg(ap, float *)) == 0) {
                        va_end(ap);
                        return n;
                    }
                    else
                        n++;
                    break;
                case 's':
                    if (scanf("%s", va_arg(ap, char *)) == 0) {
                        va_end(ap);
                        return n;
                    }
                    else
                        n++;
                    break;
            }
        } else {
            while (isspace(c = getchar()));

            if (c != *fmt) {
                va_end(ap);
                return n;
            }   
        }
    }
    va_end(ap);
    return n;
}

int main() {
    int x = 0;
    float y = 0.0;
    char s[1024];
    printf("%d\n", minscanf("hello  %d %f %s", &x, &y, s));
    printf("%d %f %s\n", x, y, s);
}