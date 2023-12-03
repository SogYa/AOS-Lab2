#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int pid;

    pid = fork();

    if (pid == 0)
    {
        execvp(argv[1], argv + 1);
        system(argv[1]);
    }
    else
    {
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}