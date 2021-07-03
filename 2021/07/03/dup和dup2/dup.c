#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int fd = open(argv[1], O_APPEND | O_RDWR);
    int new_fd = dup(fd);
    write(new_fd, "//test write", 12);
    printf("new fd = %d\n", new_fd); // 4
    return 0;
}