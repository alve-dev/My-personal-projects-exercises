/*4. Crear una cadena que tenga la siguiente frase
"Hola que tal", luego crear otra cadenas para preguntarle al ususario su nombre,
por ultimo añadir el nombre al final de la primera cadena y mostrar el mensaje
completo "Hola que tal (Nombre Del Usuario)". */

#include <iostream>
#include <cstring>

int main(void)
{
    using std::cout, std::endl, std::cin;

    char str_1[] = "Hola que tal ";
    char str_2[50];
    cout << "Cual es tu nombre?: ";
    cin.getline(str_2, 50, '\n');

    strcat(str_1, str_2);

    cout << str_1 << endl;
    return 0;
}