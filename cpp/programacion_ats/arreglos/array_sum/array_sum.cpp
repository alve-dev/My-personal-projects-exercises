//1. Escribe un programa que defina un vector de numeros y calcule la suma de sus elementos.

#include <iostream>

int main(void)
{
    int array_numeros[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //55

    int array_sum = 0;
    for (int i = 0; i < 10; i++)
    {
        array_sum += array_numeros[i];
    }

    std::cout << "\nLa suma de el array es: " << array_sum << std::endl;
    return 0;
}