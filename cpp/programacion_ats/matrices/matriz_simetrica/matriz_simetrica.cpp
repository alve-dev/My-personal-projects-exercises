/*7. Desarrollar un programa que determine si una matriz es simetrica o no. Una matriz
es simetrica si es cuadrada y si es igual a su matriz transpuesta.
*/

#include <iostream>

int main(void)
{
    using std::cout, std::endl;

    int matriz[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matriz_transpuesta[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matriz_transpuesta[i][j] = matriz[j][i];
        }
    }

    int equal = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matriz[i][j] == matriz_transpuesta[i][j])
            {
                equal++;
            }
        }
    }

    if (equal == 9)
    {
        cout << "La matriz es simetrica.\n";
    }
    else
    {
        cout << "La matriz no es simetrica.\n";
    }

    return 0;
}