#include<stdio.h>

int inRange(char c, char low, char high) {
    return c >= low && c <= high;
}

void expand(char s1[], char s2[]) {
    int i, j;
    char prev1 = '\0';
    char prev2 = '\0';
    char c;
    for (i = 0, j = 0; s1[i] != '\0'; i++) {
        if (prev1 == '-' && 
            ((inRange(prev2, 'a', 'z') && inRange(s1[i], 'a', 'z')) ||
            (inRange(prev2, 'A', 'Z') && inRange(s1[i], 'A', 'Z')) ||
            (inRange(prev2, '0', '9') && inRange(s1[i], '0', '9')))) {
            c = prev2;
            j -= 2;
            while (c != s1[i]) {
                s2[j++] = c;
                c++;
            }
            s2[j++] = s1[i];
        } else {
            s2[j++] = s1[i];
        }
        
        prev2 = prev1;
        prev1 = s1[i];
    }

    s2[j] ='\0';
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

    while(getLine(t, 1024) != 0) {
        expand(t, s);
        printf("%s\n", s);
    }
}