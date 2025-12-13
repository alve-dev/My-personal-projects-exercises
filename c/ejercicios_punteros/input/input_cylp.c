//input() builtin function of CyLp version 0

//Libraries and macros
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//prototypes
void *input(char *prompt, void *generic_ptr, char char_type);

int main(void)
{
    char *s;
    input("Digita un texto: ", &s, 's');
    printf("Valor: %s\n", s);
    free(s);
    s = NULL;
    
    return 0;
}

void *input(char *prompt, void *generic_ptr, char char_type)
{
    printf("%s", prompt);
    if (char_type == 'd')
    {
        scanf("%d", ((int *)generic_ptr));
    }
    else if (char_type == 'f')
    {
        scanf("%f", ((float *)generic_ptr));
    }
    else if (char_type == 's')
    {
        char buffer[100];
        if (fgets(buffer, sizeof(buffer), stdin) != NULL)
        {
            buffer[strcspn(buffer, "\n")] = '\0';
        }
        char **dest_ptr = (char**)generic_ptr;
        *dest_ptr = malloc(strlen(buffer) + 1);
        if (*dest_ptr == NULL)
        {
            printf("Error Alloc Memory\n");
        }
        
        strcpy(*dest_ptr, buffer);
    }
}