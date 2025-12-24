#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_strdup(const char *s);

int main(void)
{
    /*char *src = "Hola";
    char *copy;

    copy = my_strdup(src);

    printf("%s\n", src);
    printf("%s\n", copy);
    free(copy);
    copy = NULL;

    return 0;*/

    int n = 5;
    char **array = malloc(n * sizeof(char *));

    array[0] = my_strdup("Hola");
    array[1] = my_strdup("Mundo");
    array[2] = my_strdup("Python");
    array[3] = my_strdup("C/C++");
    array[4] = my_strdup("Akon Programming Language");

    for (int i = 0; i < n; i++)
    {
        printf("%s\n", array[i]);
    }

    for (int i = 0; i < n; i++)
    {
        free(array[i]);
        array[i] = NULL;
    }
    free(array);
    array = NULL;
    return 0;
}

char *my_strdup(const char *s)
{
    char *dup_s = malloc(strlen(s) + 1);
    if (dup_s == NULL)
    {
        return NULL;
    }
    strcpy(dup_s, s);
    return dup_s;
}