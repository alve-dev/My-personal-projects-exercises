/*8. Realice un programa que calcule el producto de dos matrices
cuadradas de 3 * 3.*/

#include <iostream>

int main(void)
{
    using std::cout, std::endl;

    int matriz_1[2][2] = {{1, 3}, {2, 1}};
    int matriz_2[2][2] = {{2, 0}, {1, 2}};
    int product_matriz[2][2];

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            product_matriz[i][j] = 0;
            
            for (int k = 0; k < 2; k++)
            {
                product_matriz[i][j] += matriz_1[i][k] * matriz_2[k][j];
            }
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << product_matriz[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}