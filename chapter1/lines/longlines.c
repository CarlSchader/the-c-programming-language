#include<stdio.h>

#define MAXSTRINGLENGTH 1000
#define PRINTLENGTH 80

int getLine(char s[], int lim);

void copy(char to[], char from[]);

int main() {
    int len;
    char line[MAXSTRINGLENGTH];
    
    while ((len = getLine(line, MAXSTRINGLENGTH)) > 0) {
        if (len > PRINTLENGTH) {
            printf("%s", line);
        }
    }

    return 0;
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