/* Realizar un programa que permita cargar 15 numeros en un vector.
Una vez cargados, se necesita que el programa cuente e informe por pantalla cuantas veces se cargo el numero 3 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));

    int numbers[15];
    int cont_three = 0;

    for (int i = 0; i < 15; i++)
    {
        numbers[i] = 1 + rand() % (15);
    }

    for (int i = 0; i < 15; i++)
    {
        if (numbers[i] == 3)
        {
            cont_three++;
        }
    }

    printf("El numeros 3 se repitio %i veces en el array.\n", cont_three);
    return 0;
}
