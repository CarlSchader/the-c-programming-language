#include<stdio.h>

#define MAXLINE 1024
#define LONGLINE 80

int getLine(char s[], int lim);
int copy(char to[], char from[], int start, int end);
void foldstring(char s[], int foldLength);

int main() {
    char line[MAXLINE];

    while (getLine(line, MAXLINE) > 0) { 
        foldstring(line, LONGLINE);
    }

    return 0;
}

void foldstring(char s[], int foldLength) {
    int inSpace, i, j;

    inSpace = j = i = 0;

    while (1) {
        inSpace = 0;
        for (j = i + foldLength - 1; j >= i && s[j] != '\0'; j--) {
            if (s[j] == ' ' || s[j] == '\t') {
                inSpace = 1;
            } else if (inSpace) {
                break;
            }
        }

        if (j < i) {
            int charCount = i + foldLength;
            for (i; i < charCount; i++) {
                if (s[i] == '\0') {
                    return;
                }
                putchar(s[i]);
            }
            putchar('\n');
        } else {
            for (i; i <= j; i++) {
                if (s[i] == '\0') {
                    return;
                }
                putchar(s[i]);
            }
            putchar('\n');
        }
    }
}

int copy(char to[], char from[], int start, int end) {
    int c;
    int i = 0;

    for (i = start; i < end && from[i] != '\0'; i++) {
        to[i] = from[i];
    }

    to[i] = '\0';
    return i;
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