//13. Hacer un que realize la serie fibonacci -> 1 1 2 3 5 8 13... n

#include <iostream>

int main(void)
{
    int n;
    std::cout << "Digita el valor de n: ";
    std::cin >> n;

    int fibonacci = 1, back = 0, current;
    std::cout << std::endl;
    for (int i = 1; i <= n; i++)
    {
        std::cout << fibonacci << " ";

        current = fibonacci;
        fibonacci += back;  
        back = current;
    }

    std::cout << std::endl;
    return 0;
}