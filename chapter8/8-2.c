#include"custio.h"
#include"syscalls.h"

int main(int argc, char *argv[]) {
    FILE *fp;
    char c;

    if (argc < 2)
        return 1;
    
    fp = fopen(argv[1], "r");

    while ((c = getc(fp)) != EOF)
        write(0, &c, 1);
        // putchar(c);
    
    return 0;
}
