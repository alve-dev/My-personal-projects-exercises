//Programa que pida un numero maximo, y que luego muestre en terminal desde 1 hasta ese numero maximo

#include <stdio.h>

int main(void)
{
    int n;
    printf("Digita un numero: ");
    scanf("%i", &n);

    for (int i = 1; i <= n; i++)
    {
        printf("%i\n", i);
    }
    return 0;
}