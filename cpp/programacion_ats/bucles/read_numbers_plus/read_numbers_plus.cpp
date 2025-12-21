/*5. Escriba un programa que lea valores enteros hasta que se introduzca un valor en el rango [20-30]
o se introduzca el valor 0. El programa debe entregar la suma de los valores mayores a 0 introducidos.*/

#include <iostream>

int main(void)
{
    int number, sum = 0;

    do
    {
        std::cout << "Digita un numero: ";
        std::cin >> number;
        sum += number;

    } while ((number < 20 || number > 30) && number != 0);

    std::cout << "\nLa suma de todos los numeros mayores a 0 ingreasados: " << sum << std::endl;
    return 0;
    
}