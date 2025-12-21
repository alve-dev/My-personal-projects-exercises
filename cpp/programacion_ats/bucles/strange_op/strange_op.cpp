//12. Hacer un programa que calcule el resultado de la siguiente expresion 1-2+3-4+5-6...n

#include <iostream>

int main(void)
{
    int n;
    std::cout << "Digita el valor de n: ";
    std::cin >> n;

    int operation = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            operation -= i;
        }
        else
        {
            operation += i;
        }
    }

    std::cout << "La operacion final: " << operation << std::endl;
    return 0;
}