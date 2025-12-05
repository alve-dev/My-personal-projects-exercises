#include <stdio.h>

int fact_r(int n);
int fact_i(int n);

int main(void)
{
    printf("Factorial de 5 con recursibidad: %i\n", fact_r(5));
    printf("Factorial de 5 con iterabilidad: %i\n", fact_i(5));
    return 0;
}
//Funcion factorial con recursividad
int fact_r(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return n * fact_r(n-1);
    }
}

//Funcion factorial con iterabilidad
int fact_i(int n)
{
    int result = 1;
    for(int i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}