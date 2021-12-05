#include"custio.h"
#include"syscalls.h"

int main(int argc, char *argv[]) {
    FILE *fp;
    char c;

    if (argc < 2)
        return 1;
    
    fp = fopen(argv[1], "r");
    fseek(fp, 20, 0);

    while ((c = getc(fp)) != EOF) {
        putchar(c);
    }

    fclose(stdout);

    return 0;
}
