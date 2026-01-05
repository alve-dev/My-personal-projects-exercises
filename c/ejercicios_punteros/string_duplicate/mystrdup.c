//1. Implementa una función que duplique una cadena usando malloc.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *mystrdup(const char *src);

int main(void)
{
    char *name = "Alejandro";
    char *cpy_name = mystrdup(name);
    if (cpy_name == NULL) {return 1;}

    printf("%s\n", cpy_name);

    free(cpy_name);
    cpy_name = NULL;
    
    return 0;
}

char *mystrdup(const char *src)
{
    char *string_copy = malloc(strlen(src) + 1);
    if (string_copy == NULL) {return NULL;}

    strcpy(string_copy, src);
    return string_copy;
}