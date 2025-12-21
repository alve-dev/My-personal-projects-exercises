/*6. Escriba un programa que calcule x^y,
donde tanto x como y son enteros positivos,
sin utilizar la funcion pow
*/

#include <iostream>

int main(void)
{
    int base;
    std::cout << "Digita el valor para una base de exponenciacion: ";
    std::cin >> base;

    int exponente;
    std::cout << "Digita el valor de el exponente: ";
    std::cin >> exponente;

    int potencia = 1;
    for (int i = 1; i <= exponente; i++)
    {
        potencia *= base;
    }

    std::cout << "La potencia de " << base << "^" << exponente << " es: " << potencia << std::endl;
    return 0;
}