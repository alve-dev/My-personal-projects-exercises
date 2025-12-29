// builtin function readFloat de Akon Programming Language en C

#include <stdio.h>

float readFloat(const char *prompt);
float readFloat_m(const char *prompt, float min, float max);

int main(void)
{
    float f = readFloat_m("Type a floating-point number: ", 0.0, 10.0);
    printf("%f\n", f);
    return 0;
}

float readFloat(const char *prompt)
{
    float input_float;
    printf("%s", prompt);
    scanf("%f", &input_float);
    return input_float;
}

float readFloat_m(const char *prompt, float min, float max)
{
    float input_float = readFloat(prompt);
    while (input_float < min || input_float > max)
    {
        input_float = readFloat(prompt);
    }

    return input_float;
}