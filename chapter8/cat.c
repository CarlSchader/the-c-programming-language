#include<fcntl.h>
#include"syscalls.h"

int main(int argc, char *argv[]) {
    int fd;
    char buff[BUFFSIZE];
    int n;

    if (argc == 1) {
        while ((n = read(0, buff, BUFFSIZE)) > 0) {
            if (write(1, buff, n) != n) {
                write(2, "error: write error\n", 19);
                return 2;
            }
        }
    }

    for (; argc > 1; argc--, argv++) {
        if ((fd = open(*argv, O_RDONLY, 0)) == -1) {
            write(2, "error: read error\n", 18);
            close(fd);
            return 1;
        } else {
            while ((n = read(fd, buff, BUFFSIZE)) > 0) {
                if (write(1, buff, n) != n) {
                    write(2, "error: write error\n", 19);
                    close(fd);
                    return 2;
                }
            }
            close(fd);
        }
    }

    return 0;
}
