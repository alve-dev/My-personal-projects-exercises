/*1. Hacer un programa que pida al usuario que
digite una cadena de caracteres, luego verificar la longitud de la cadena,
y si esta supera a 10 caracteres mostrarla en pantalla, caso contratio no mostrarla
*/

#include <iostream>
#include <cstring>

int main(void)
{
    using std::cout, std::cin, std::endl;

    char cadena[11];
    cout << "Digita una palabra: ";
    cin.getline(cadena, 12, '\n');

    if (strlen(cadena) < 11)
    {
        cout << cadena << endl;
    }

    return 0;
}