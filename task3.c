#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    printf("Начало программы\n ID процесса: %i\n ID родительского процесса: %i\n ID группы: %i\n", getpid(), getppid(), getgid());
    int fork_process = fork();
    printf("После создания нового процесса\n ID процесса: %i\n ID родительского процесса: %i\n ID группы: %i\n", getpid(), getppid(), getgid());

    if (fork_process)
    {
        int child_status;
        pid_t child_procces_id = wait(child_status);
        printf("Дочерний процесс заврешил работу\n ID процесса: %i\n Cтатус дочернего процесса: %i\n", child_procces_id, child_status);
    }
    exit(EXIT_SUCCESS);
}