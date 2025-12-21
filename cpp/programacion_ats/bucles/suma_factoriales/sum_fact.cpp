//10. Escriba un programa que calcule el valor de: 1!+2!+3!+...+n!(suma de factoriales)

#include <iostream>

int main(void)
{
    int n;
    std::cout << "Digita el valor de n: ";
    std::cin >> n;

    int fact = 1, sum_fact = 0;
    for(int i = 1; i <= n; i++)
    {
        fact *= i;
        sum_fact += fact;
    }

    std::cout << "\nLa suma de factoriales es: " << sum_fact << std::endl;
    return 0;
}