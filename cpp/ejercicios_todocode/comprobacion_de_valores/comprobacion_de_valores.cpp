/* Realizar un programa que permita cargar 15 numeros en un vector.
Una vez cargados, se necesita que el programa cuente e informe por pantalla cuantas veces se cargo el numero 3 */

#include <iostream>
#include <stdlib.h>
#include <ctime>

int main(void)
{
    srand(time(NULL));
    
    int numbers[15];
    int count_three = 0;

    for (int i = 0; i < 15; i++)
    {
        numbers[i] = 1 + rand() % 15;
    }

    for (int i = 0; i < 15; i++)
    {
        if (numbers[i] == 3)
        {
            count_three++;
        }
    }

    std::cout << "El numero 3 se repitio " << count_three << " veces en el array.\n";
    return 0;
}