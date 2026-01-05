/*2. Pedir al usuario una cadena de caracteres, almacenarla en un arreglo y copiar todo
su contenido hacia otro arreglo de caracteres.*/

#include <iostream>
#include <cstring>

int main(void)
{
    using std::cout, std::endl, std::cin;

    char string[50];
    cout << "Digita una palabra: ";
    cin.getline(string, 50, '\n');

    char string_2[50];
    strcpy(string_2, string);

    cout << string_2 << endl;
    return 0;
}