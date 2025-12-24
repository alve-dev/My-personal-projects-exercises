/*15. realice un programa que solicite al usuario que piense un numero entero
entre el 1 y el 100. El programa debe generar un numero aleatorio en ese mismo
rango[1-100], e indicarle al usuario si numero que digito es menor o mayor
al numero aleatorio, asi hasta que lo adivine y por ultimo mostrarle el numero
de intentos que le llevo.

variable = limite_inferior + rand() % (limite _superior +1 - limite_inferior);
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

int main(void)
{
    srand(time(NULL));
    int random_num = 1 + rand() % (100);

    int number, count = 0;
    do
    {
        std::cout << "Digita un numero[1-100]: ";
        std::cin >> number;

        if (number < 1 || number > 100)
        {
            std::cout << "El rango es de 1 a 100\n\n";
            continue;
        }
        else if (number > random_num)
        {
            std::cout << "Intenta un numero mas pequeño\n\n";
        }
        else if (number < random_num)
        {
            std::cout << "Intenta un numero mas grande\n\n";
        }
        count++;

    } while (number != random_num);

    std::cout << "\nFelicidades! te tomo " << count << " intentos\n";
    return 0;
}