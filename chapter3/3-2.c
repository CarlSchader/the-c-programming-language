#include<stdio.h>

void escape(char s[], char t[]) {
    int i = 0;
    int j = 0;
    while (t[i] != '\0') {
        switch (t[i]) {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:
                s[j++] = t[i];
                break;
        }
        i++;
    }

    s[j] = '\0';
}

void reverse(char s[], char t[]) {
    int i = 0;
    int j = 0;
    while (t[i] != '\0') {
        switch (t[i]) {
            case '\\':
                i++;
                if (t[i] == 'n') {
                    s[j++] = '\n';
                } else if (t[i] == 't') {
                    s[j++] = '\t';
                } else {
                    s[j++] = '\\';
                    s[j++] = t[i];
                }
                break;
            default:
                s[j++] = t[i];
                break;
        }
        i++;
    }

    s[j] = '\0';
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
    char t[1024];

    while(getLine(s, 1024) != 0) {
        escape(t, s);
        printf("%s\n", t);
        reverse(t, t);
        printf("%s\n", t);
    }
}