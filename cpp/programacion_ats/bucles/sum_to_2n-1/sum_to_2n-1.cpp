//8. Escriba un programa que calcule el valor de: 1+3+5+...+2n-1

#include <iostream>

int main(void)
{
    int n;

    do
    {
        std::cout << "Digita el valor de n(mayor a 0): ";
        std::cin >> n;
    } while (n < 1);
    
    n = (n * 2) - 1;
    int suma = 0, step = -1;

    for (int i = 1; i <= n; i++)
    {
        step += 2;
        suma += step;
    }

    std::cout << "\nLa suma es: " << suma << std::endl;
    return 0;
}