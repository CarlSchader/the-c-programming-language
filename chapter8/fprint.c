#include<stdio.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>
#include<sys/types.h>

#define MAX_PATH 1024

void statprint(struct stat *stbuf, char *name) {
    printf("%s:\n", name);
    printf("\tdevice: %d\n", stbuf->st_dev);
    printf("\tinode: %llu\n", stbuf->st_ino);
    printf("\tmode: %o\n", stbuf->st_mode);
    printf("\tlink: %hu\n", stbuf->st_nlink);
    printf("\towner's user id: %u\n", stbuf->st_uid);
    printf("\towner's group id: %u\n", stbuf->st_gid);
    printf("\tspecial: %d\n", stbuf->st_rdev);
    printf("\tsize: %lld\n", stbuf->st_size);
    printf("\tlast accessed: %ld\n", stbuf->st_atime);
    printf("\tlast modified: %ld\n", stbuf->st_mtime);
    printf("\tlast inode change: %ld\n", stbuf->st_ctime);
    putchar('\n');
}

void dirwalk(char *dir, void (*fcn)(char *)) {
    char name[MAX_PATH];
    struct dirent *dp;
    DIR *dfd;

    if ((dfd = opendir(dir)) == NULL) {
        fprintf(stderr, "dirwalk: can't open %s\n", dir);
        return;
    }
    while ((dp = readdir(dfd)) != NULL) {
        if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0)
            continue;
        if (strlen(dir) + strlen(dp->d_name) + 2 > sizeof(name))
            fprintf(stderr, "dirwalk: name %s/%s too long\n", dir, dp->d_name);
        else {
            sprintf(name, "%s/%s", dir, dp->d_name);
            (*fcn)(name);
        }
    }
    closedir(dfd);
}

void fprint(char *name) {
    struct stat stbuf;
    
    if (stat(name, &stbuf) == -1)
        fprintf(stderr, "fprint: can't access %s\n", name);
    
    if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
        dirwalk(name, fprint);
    statprint(&stbuf, name);
}

int main(int argc, char **argv) {
    if (argc == 1)
        fprint(".");
    else
        while (--argc > 0)
            fprint(*++argv);
    return 0;
}