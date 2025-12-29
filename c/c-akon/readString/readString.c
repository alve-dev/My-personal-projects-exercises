// builtin function readString de AkonProgramming Language en C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *readString(char *prompt);
//char *readString_m(char *prompt, int limit);

int main(void)
{
    char *s = readString(">> ");
    printf("%s\n", s);
    return 0;
}

char *readString(char *prompt)
{
    char input_string[100];
    get
    if (fgets(input_string, sizeof(input_string), stdin) != NULL)
    {
        input_string[str] = '\0';
    }
    return input_string;
}