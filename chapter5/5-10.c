#include<stdio.h>
#include<stdlib.h>

#define STACKSIZE 1024

float stack[STACKSIZE];
float *sp = stack;

int push(float s) {
    if (sp >= (stack + STACKSIZE)) {
        printf("push error: stack full\n");
        return -1;
    } else {
        *sp = s;
        sp++;
        return 0;
    }
}

float pop() {
    if (sp <= stack) {
        printf("pop error: stack empty\n");
        return -1;
    } else {
        sp--;
        return *sp;
    }
}

void printstack() {
    float *p;
    for (p = stack; p < sp; ++p)
        printf(sp - p == 1 ? "%.3f" : "%.3f ", *p);
    putchar('\n');
}

int main(int argc, char *argv[]) {
    int op2;
    for (++argv; argc > 1; argc--, argv++) {
        switch ((*argv)[0]) {
            case '+':
                push(pop() + pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                op2 = pop();
                push(pop() / op2);
                break;
            default:
                push(atof(*argv));
                break;
        }
    }
    printstack();
}