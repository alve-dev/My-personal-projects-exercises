//7. Escriba un programa que calcule el valor de: 1+2+3+....+n

#include <iostream>

int main(void)
{
    int n;
    std::cout << "Digita un valor: ";
    std::cin >> n;

    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }

    std::cout << "La suma es: " << sum << std::endl;
    return 0;
}