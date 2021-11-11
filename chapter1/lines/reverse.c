#include<stdio.h>

#define MAXSTRINGLENGTH 1000
#define TRUE 1
#define FALSE 0

int getLine(char s[], int lim);

void copy(char to[], char from[]);

int reverse(char s[]);

int main() {
    char line[MAXSTRINGLENGTH];
    
    while (getLine(line, MAXSTRINGLENGTH) > 0) {
        reverse(line);
        printf("%s", line);
    }

    return 0;
}

int reverse(char line[]) {
    int len, i;
    char c;

    for (len = 0; line[len] != '\0'; len++);

    for (i = 0; i < len / 2; i++) {
        c = line[i];
        line[i] = line[len - 1 - i];
        line[len - 1 - i] = c;
    }
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

void copy(char to[], char from[]) {
    int c;
    int i = 0;

    for (i = 0; from[i] != '\0'; i++) {
        to[i] = from[i];
    }

    to[i] = '\0';
}