#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>

int main(int argc, char *argv[]) {
    int fd1 = open(argv[1], O_RDWR);    // 3
    int fd2 = open(argv[2], O_RDWR);    // 4

    int fdret = dup2(fd1, fd2);
    printf("fdret = %d\n", fdret);

    char str[] = "#//1234567";
    int ret = write(fd2, str, strlen(str));
    dup2(fd1, STDOUT_FILENO);

    printf("#------------------------886\n");

    return 0;
}