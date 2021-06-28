#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>
#include <string.h>

void sys_err(char *str) {
    perror(str);
    exit(1);
}

int main()
{
    int fd[2]; // 0读 1写
    if (pipe(fd) == -1) {
        perror("pipe error");
    }
    pid_t pid = fork();
    if (pid > 0) {
        // 父进程关闭读端
        printf("%s\n", "父进程");
        close(fd[0]);
        char *msg = "Hello World\n";
        write(fd[1], msg, strlen(msg));
        sleep(1); // 防止父进程提前退出
        close(fd[1]);
    } else {
        // 子进程关闭写端
        printf("%s\n", "子进程");
        close(fd[1]);
        char buf[1024];
        int ret = read(fd[0], buf, sizeof(buf));
        write(STDOUT_FILENO, buf, ret);
        close(fd[0]);
    }

    return 0;
}