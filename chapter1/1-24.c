#include<stdio.h>

#define MAXLINE 1024
#define STACKSIZE 1024
#define SETSIZE 3

int inSet(char c, char set[], int setSize);

int main() {
    char stack[1024];
    int c, slash, comment, dcomment, i, j, squote, dquote, line;

    char opening_set[] = {'(', '[', '{'};
    char closing_set[] = {')', ']', '}'};
    
    slash = comment = dcomment = i = j = squote = dquote = slash = 0;
    line = 1;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            ++line;
        } 
        
        if (comment) {
            if (comment == 1) {
                if (c == '*') {
                    comment = 2;
                }
            } else if (comment == 2) {
                if (c == '/') {
                    comment = 0;
                } else {
                    comment = 1;
                }
            }
        } else if (dcomment) {
            if (dcomment == 1) {
                if (c == '/') {
                    dcomment = 2;
                } else if (c == '*') {
                    dcomment = 0;
                    comment = 1;
                } else {
                    dcomment = 0;
                }
            } else if (dcomment == 2) {
                if (c == '\n') {
                    dcomment = 0;
                }
            }
        } else if (squote) {
            if (!slash && c == '\'') {
                squote = 0;
            }
        } else if (dquote) {
            if (!slash && c == '\"') {
                dquote = 0;
            }
        } else {
            if (c == '\\' || slash) {
                slash = (slash + 1) % 3;
            } else if (c == '/') {
                dcomment = 1;
            } else if (c == '\'') {
                squote = 1;
            } else if (c == '\"') {
                dquote = 1;
            } else if ((j = inSet(c, closing_set, SETSIZE)) != -1) {
                if (stack[i] == opening_set[j]) {
                    stack[i] = 0;
                    --i;
                } else {
                    printf("Error, mismatched %c with %c on line %d\n", stack[i], c, line);
                    return 1;
                }
            } else if ((j = inSet(c, opening_set, SETSIZE)) != -1) {
                ++i;
                stack[i] = c;
            }
        }
    }

    return 0;
}

int inSet(char c, char set[], int setSize) {
    int i;
    for (i = 0; i < setSize; i++) {
        if (c == set[i]) {
            return i;
        }
    }
    return -1;
}
