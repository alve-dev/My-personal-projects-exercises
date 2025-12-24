/*5. Desarrolle un programa que lea de la entrada estandar un vector de enteros y determine el mayor elemento del vector*/

#include <iostream>

int main(void)
{
    using std::cout, std::cin, std::endl;
    srand(time(NULL));

    int numbers[10];
    for (int i = 0; i < 10; i++)
    {
        numbers[i] = 1 + rand() % (10);
        cout << numbers[i] << " ";
    }

    int max;
    for (int i = 0; i < 10; i++)
    {
        if (i == 0)
        {
            max = numbers[i];
            continue;
        }
        else if (numbers[i] > max)
        {
            max = numbers[i];
        }
    }

    cout << "\nEl numero maximo es " << max << endl;
    return 0;
}