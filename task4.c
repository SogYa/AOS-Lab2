#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    printf("Начало программы\n ID процесса: %i\n ID родительского процесса: %i\n ID группы: %i\n", getpid(), getppid(), getgid());
    int fork_process = fork();
    printf("После создания нового процесса\n ID процесса: %i\n ID родительского процесса: %i\n ID группы: %i\n", getpid(), getppid(), getgid());

    if (fork_process == 0)
    {
        sleep(5);
        printf("Дочерний процесс полсе смерти родителя\n ID процесса: %i\n ID родительского процесса: %i\n ID группы: %i\n", getpid(), getppid(), getgid());
    }
    exit(EXIT_SUCCESS);
}