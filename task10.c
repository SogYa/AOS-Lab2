#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char * argv[], char * envp[]) {
    int fork_process = fork();

    if (fork_process == 0) {
        printf("Родительский процесс\n");
        printf("Параметры\n");
        for (char** it = argv; *it; it++) {
            printf("%s\n", *it);
        }
        printf("\nenv\n");
        for (char** it = envp; *it; it++) {
            printf("%s\n", *it);
        }

    } else {
        int er = execvp(argv[1], argv + 1);
        printf("Ошибка: %d\n", er);
    }

    exit(EXIT_SUCCESS);
}