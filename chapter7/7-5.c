#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100
#define MAXVAR 26
#define LASTPRINTVAR 'L'

int sp = 0;
double val[MAXVAL];

double vars[MAXVAR];
int vp = 0;

int getop(char []);
void push(double);
double pop(void);
void print(double);

int main() {
    int type;
    double op2;
    double op3;
    char s[MAXOP];

    for (vp = 0; vp < MAXVAR; vp++)
        val[vp] = 0.0;
    vp = 0;

    while ((type = getop(s)) != EOF) {
        if (type >= 'A' && type <= 'Z') {
            vp = type - 'A';
            push(vars[vp]);
        } else {
            switch (type) {
                case NUMBER:
                    push(atof(s));
                    break;
                case '+':
                    push(pop() + pop());
                    break;
                case '*':
                    push(pop() * pop());
                    break;
                case '-':
                    op2 = pop();
                    push(pop() - op2);
                    break;
                case '/':
                    op2 = pop();
                    push(pop() / op2);
                    break;
                case '%':
                    op2 = pop();
                    push((int)pop() % (int)op2);
                    break;
                case 's':
                    push(sin(pop()));
                    break;
                case 'e':
                    push(exp(pop()));
                    break;
                case 'p':
                    op2 = pop();
                    push(pow(pop(), op2));
                    break;
                case 't':
                    op2 = pop();
                    print(op2);
                    push(op2);
                    break;
                case 'd':
                    op2 = pop();
                    push(op2);
                    push(op2);
                    break;
                case 'w':
                    op2 = pop();
                    op3 = pop();
                    push(op2);
                    push(op3);
                    break;
                case 'c':
                    sp = 0;
                    break;
                case '=':
                    op2 = pop();
                    push(op2);
                    vars[vp] = op2;
                    break;
                case '\n':
                    print(pop());
                    break;
                default:
                    printf("error: unknown command %s\n", s);
                    break;
            }
        }
    }
    
    return 0;
}

void print(double val) {
    printf("\t%.8g\n", val);
    vars[LASTPRINTVAR - 'A'] = val;
}

void push(double f) {
    if (sp < MAXVAL) {
        val[sp++] = f;
    } else {
        printf("error: stack full, can't push %g\n", f);
    }
}

double pop(void) {
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

int getop(char s[]) {
    int i, c;

    static int buf = 0;

    while((s[0] = c = (buf ? buf : getchar())) == ' ' || c == '\t')
        buf = 0;

    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;
    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = (buf ? buf : getchar())))
            buf = 0;
    
    if (c == '.')
        while (isdigit(s[++i] = c = (buf ? buf : getchar())))
            buf = 0;
    
    s[i] = '\0';
    if (c != EOF) {
        buf = c;
    }

    return NUMBER;
}