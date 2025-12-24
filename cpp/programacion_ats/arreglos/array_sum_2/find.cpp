/*6. Escribe un programa que defina un vector de numeros y calcule si existe algun numero en el vector
cuyo valor equivale a la suma del resto de numeros del vector
*/

#include <iostream>

int main(void)
{
    using std::cout, std::endl;

    int array[] = {1, 2, 3, 4, 10};    
    int sum_array = 0;

    cout << "Los numeros que so iguales a a suma del resto de los elementos son: ";
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (j == i)
            {
                continue;
            }
            sum_array += array[j];
        }

        if (array[i] == sum_array)
        {
            cout << array[i] << " ";
        }

        sum_array = 0;
    }
    cout << endl;

    return 0;
}