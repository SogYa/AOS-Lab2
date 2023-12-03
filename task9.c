#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>

extern int errno;

int main(int argc, char *argv[])
{
    int input_file, result_file, fork_result;
    ssize_t r;

    if (argc != 2)
    {
        printf("Не верное количество аргументов", argv[0]);
        exit(EXIT_FAILURE);
    }

    printf("open: %s\n", strerror(errno));
    fork_result = fork();
    const char *filename = argv[1];
    input_file = open(filename, O_RDWR);
    

    if (fork_result)
    {
        filename = "parent_file";
    }
    else
    {
        filename = "child_file";
    }
    result_file = open(filename, O_RDWR | O_CREAT, 0644);

    char buf[256];
    do
    {
        r = read(input_file, buf, sizeof(buf));
        write(result_file, buf, r);
        memset(buf, '\0', sizeof(buf));
    } while (r == sizeof(buf));

    lseek(result_file, 0, SEEK_SET);

    if (fork_result)
    {
        int child_result;
        wait(&child_result);
        printf("Родитель окончил работу\n");
    }
    else
    {
        printf("Ребенок окончил работу\n");
    }

    do
    {
        r = read(result_file, buf, sizeof(buf));
        printf("%s", buf);
        memset(buf, '\0', sizeof(buf));
    } while (r == sizeof(buf));

    exit(EXIT_SUCCESS);
}