//9. Escriba un programa que calcule el valor de: 1*2*3*...*n(factorial)

#include <iostream>

int main(void)
{
    int n;
    std::cout << "Digita un numero para n!: ";
    std::cin >> n;

    int factorial = 1;
    for (int i = 1; i <= n; i++)
    {
        factorial *= i;
    }
    
    std::cout << n << "! = " << factorial << std::endl;
    return 0;
}