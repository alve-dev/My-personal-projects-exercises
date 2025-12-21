//11. Escriba un programa que calcule el valor de: 2^1+2^2+2^3+...+2^n

#include <iostream>

int main(void)
{
    int n;
    std::cout << "Digita el valor de n: ";
    std::cin >> n;

    int suma = 0;
    for (int i = 1; i <= n; i++)
    {
        suma += i*i;
    }

    std::cout << "\nLa suma de potenciaciones es: " << suma << std::endl;
    return 0;
}