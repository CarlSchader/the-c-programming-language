#include<stdio.h>

#define MAXSTRINGLENGTH 1000
#define TRUE 1
#define FALSE 0

int getLine(char s[], int lim);

void copy(char to[], char from[]);

int removeTrail(char line[]);

int main() {
    int len;
    char line[MAXSTRINGLENGTH];
    
    while (getLine(line, MAXSTRINGLENGTH) > 0) {
        if ((len = removeTrail(line)) > 1) {
            printf("%s", line);
        }
    }

    return 0;
}

int removeTrail(char line[]) {
    int i;

    for (i = 0; line[i] != '\n' && line[i] != '\0'; i++);

    for (i = i - 1; i >= 0 && (line[i] == ' ' || line[i] == '\t'); i--);

    line[i + 1] = '\n';
    line[i + 2] = '\0';

    return i + 2;
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