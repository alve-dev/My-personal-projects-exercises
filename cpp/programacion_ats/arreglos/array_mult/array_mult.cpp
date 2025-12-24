//2. Escribe un programa que defina un vector de numeros y calcule la multiplicacion acumulada de sus elementos.

#include <iostream>

int main(void)
{
    int array_numbers[] = {1, 2, 3, 4, 5};
    int array_mult = 1;

    for (int i = 0; i < 17; i++)
    {
        array_mult *= array_numbers[i];
    }

    std::cout << "\nLa multiplicacion del array es: " << array_mult << std::endl;
    return 0;
}