#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main()
{
    int pid = fork();
    if (pid)
    {
        printf("Это дочерний fork");
    }
    else
    {
        printf("Это родительский fork");
    }
    return 0;
}