//Libraries and macros
#include <stdio.h>
#include <stdlib.h>

//Prototypes
void str_revert(char s[]);

int main(void)
{
    char s[] = "Hola";
    str_revert(s);
    printf("Hola, %s\n", s);
    return 0;
}

void str_revert(char s[])
{
    char *end = s;
    char *start = s;
    char temp;
    while (*end != '\0')
    {
        end++;
    }
    end--;

    while (start < end)
    {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}