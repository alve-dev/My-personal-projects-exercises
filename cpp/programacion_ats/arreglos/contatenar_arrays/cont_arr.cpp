/*7. Realiza un programa que defina dos vectores de caracteres y despues almacene el
contenido de ambos vectores en un nuevo vector, situado en primer lugar los elemnetos
del primer vector seguido por los elementos del segundo vector. Muestre el contenido
del nuevo vector en la salida estandar. */

#include <iostream>

int main(void)
{
    using std::cout, std::endl;
    char word_1[5] = "Hola";
    char word_2[6] = "Mundo";
    char word_3[10];

    for (int i = 0; i < 10; i++)
    {
        if (i < 4)
        {
            word_3[i] = word_1[i];
        }
        else
        {
            word_3[i] = word_2[i-4];
        }
    }

    cout << word_3 << endl;
    return 0;
}