/*4. Escribe un programa que defina un vector de numeros y muestre en la salida estandar el vector en el orden inverso
del ultimo al primer elemento.
*/

#include<iostream>
#include<cstdlib>
#include<ctime>

int main(void)
{
    using std::cout, std::cin, std::endl;
    srand(time(NULL));

    int numbers[10];
    for (int i = 0; i < 10; i++)
    {
        numbers[i] = 1 + rand() % (10);
    }

    for (int i = 0; i < 10; i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;

    for (int i = 9; i >= 0; i--)
    {
        cout << numbers[i] << " ";
    } 
    cout << endl;

    return 0;
}