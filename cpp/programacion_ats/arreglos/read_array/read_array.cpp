/*3. Escribe un prograna que lea de la entrada estandar un vectir de nuneros y
muestre en la salida estandar los numeros del vector con sus indices asociados.*/

#include <iostream>

int main(void)
{
    int numbers[100], n;
    std::cout << "Digita cuantos elementos quieres poner en tu array[max: 100]: ";
    std::cin >> n;
    
    int number;
    for (int i = 0; i < n; i++)
    {
        std::cout << "Digita un numero: ";
        std::cin >> number;

        numbers[i] = number;
    }

    std::cout << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << i << " : " << numbers[i] << std::endl;
    }

    return 0;
}