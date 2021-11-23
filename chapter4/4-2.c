#include<stdio.h>
#include<string.h>

void trim(char s[]) {
    int i;
    for (i = strlen(s) - 1; i >= 0 && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'); i--)
        ;
    s[i + 1] = '\0';
}

double atof(char s[]) {
    int i = 0;
    int len = strlen(s);
    int sign = 1;
    double val = 0.0;

    for (i = 0; i < len && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'); i++)
        ;

    if (i < len && s[i] == '-') {
        sign = -1;
        i++;
    }

    for (; i < len && s[i] >= '0' && s[i] <= '9'; i++) {
        val = (10.0 * val) + (s[i] - '0');
    }

    if (i < len && s[i] == '.') {
        i++;
    }

    double power = 1.0;
    for (; i < len && s[i] >= '0' && s[i] <= '9'; i++) {
        val = (10.0 * val) + (s[i] - '0');
        power /= 10.0;
    }

    if (i < len && (s[i] != 'E' || s[i] != 'e')) {
        i++;
    }

    int expsign = 1;
    if (i < len && s[i] == '-') {
        expsign = -1;
        i++;
    }

    int exponent = 0;
    for (; i < len && s[i] >= '0' && s[i] <= '9'; i++) {
        exponent = (10 * exponent) + (s[i] - '0');
    }

    for (; exponent > 0; exponent--) {
        if (expsign >= 0) {
            power *= 10.0;
        } else {
            power /= 10.0;
        }
    }

    return sign * val * power;    
}

int getLine(char s[], int lim) {
    int c, length, i;
    
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF; i++) {
        s[i] = c;
        
        if (c == '\n') {
            ++i;
            break;
        }
    }

    s[i] = '\0';
    return i;
}

int main() {
    char s[1024];

    while(getLine(s, 1024) != 0) {
        trim(s);
        printf("%f\n", atof(s));
    }
}