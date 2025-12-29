// la funcion builtin readInt de Akon Programming Language en C

#include <stdio.h>

int readInt(const char *prompt);
int readInt_m(const char *prompt, int min, int max);

int main(void)
{
    int number = readInt_m("Digita un numero: ", 0, 10);
    printf("%i\n", number);
    return 0;
}

int readInt(const char *prompt)
{
    int input_int;
    printf("%s", prompt);
    scanf("%i", &input_int);

    return input_int;
}

int readInt_m(const char *prompt, int min, int max)
{
    int input_int = readInt(prompt);
    while (input_int < min || input_int > max)
    {
        input_int = readInt(prompt);
    }
    return input_int;
}