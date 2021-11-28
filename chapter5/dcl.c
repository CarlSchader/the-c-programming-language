#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include"read.h"

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };

int dcl(void);
int dirdcl(void);
int gettoken(void);
void reset(void);

static int tokentype;
static char token[MAXTOKEN];
static char name[MAXTOKEN];
static char datatype[MAXTOKEN];
static char out[1000];

void zeroarray(char *a, int size) {
    for (; size > 0; --size, ++a)
        *a = 0;
}

void reset() {
    clearbuff();
    tokentype = 0;
    zeroarray(token, MAXTOKEN);
    zeroarray(name, MAXTOKEN);
    zeroarray(datatype, MAXTOKEN);
    zeroarray(out, 1000);
}

int main() {
    int error;
    while (gettoken() != EOF) {
        error = 0;
        strcpy(datatype, token);
        out[0] = '\0';
        error = dcl();
        if (tokentype != '\n') {
            printf("syntax error\n");
            printf("tokentype: %d\n", tokentype);
            error = 1;
        }

        if (error) {
            printf("try again\n\n");
        } else {
            printf("%s: %s %s\n", name, out, datatype);
        }
        reset();
    }

    return 0;
}

int gettoken() {
    int c, getch(void);
    void ungetch(int);
    char *p = token;

    while ((c = getch()) == ' ' || c == '\t');

    if (c == '(') {
        if ((c = getch()) == ')') {
            strcpy(token, "()");
            return tokentype = PARENS;
        } else {
            ungetch(c);
            return tokentype = '(';
        }
    } else if (c =='[') {
        for (*p++ = c; (*p++ = getch()) != ']'; );
        *p = '\0';
        return tokentype = BRACKETS;
    } else if (isalpha(c)) {
        for (*p++ = c; isalnum(c = getch()); )
            *p++ = c;
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    } else
        return tokentype = c;
}

int dcl() {
    int ns;
    int error;

    for (ns = 0; gettoken() == '*'; )
        ns++;
    error = dirdcl();
    while (ns-- > 0)
        strcat(out, " pointer to");
    
    return error;
}

int dirdcl() {
    int type;

    if (tokentype == '(') {
        dcl();
        if (tokentype != ')') {
            printf("error: missing )\n");
            return 1;
        }
    } else if (tokentype == NAME)
        strcpy(name, token);
    else {
        printf("error: expected name or (dcl)\n");
        return 1;
    }
    
    while ((type = gettoken()) == PARENS || type == BRACKETS) {
        if (type == PARENS)
            strcat(out, " function returning");
        else {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
    }

    return 0;
}