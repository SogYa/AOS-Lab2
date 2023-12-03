#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *string = calloc(256, sizeof(char));
    printf("Запись в процесс: ");
    scanf("%s", string);
    if (putenv(string) != 0)
    {
        printf("Ошибка при изменении переменной.\n");
        exit(1);
    }
    free(string);
}