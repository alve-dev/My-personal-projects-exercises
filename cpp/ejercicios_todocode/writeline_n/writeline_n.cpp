//Programa que pida un numero maximo, y que luego muestre en terminal desde 1 hasta ese numero maximo

#include <iostream>

int main(void)
{
    int n;
    std::cout << "Digita un numero: ";
    std::cin >> n;

    for (int i = 1; i <= n; i++)
    {
        std::cout << i << std::endl;
    }
    return 0;
}