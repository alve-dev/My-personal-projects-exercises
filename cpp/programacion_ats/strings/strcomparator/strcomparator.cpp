/*3. Pedir al usuario que 2 cadenas de caracteres, e indicar si ambas cadenas
son iguales, en caso de no serlo, indicar cual es mayor alfabeticamente*/

#include <iostream>
#include <cstring>

int main(void)
{
    using std::cout, std::cin, std::endl;

    char cadena_1[50];
    cout << "Digita una palabra: ";
    cin.getline(cadena_1, 50, '\n');

    char cadena_2[50];
    cout << "Digita una palabra: ";
    cin.getline(cadena_2, 50, '\n');

    if (strcmp(cadena_1, cadena_2) > 0)
    {
        cout << "Alfabeticamente " << cadena_1 << " es mayor" << endl;
    }
    else if (strcmp(cadena_1, cadena_2) < 0)
    {
        cout << "Alfabeticamente " << cadena_2 << " es mayor" << endl;
    }
    else
    {
        cout << "Las palabras son iguales." << endl;
    }


    return 0;
}