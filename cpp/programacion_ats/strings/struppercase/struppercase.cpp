//Pedir dos cadenas, volverlas mat¿yusculas y compararlas

#include <iostream>
#include <cstring>

void my_strupr(char *s)
{
    unsigned int n = strlen(s);

    unsigned int i = 0;
    while (i < n)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] = s[i] - 32;
        }
        
        i++;
    }
}

int main(void)
{
    char str_1[25];
    std::cout << "Digita una palabra: ";
    std::cin.getline(str_1, 25, '\n');

    char str_2[25];
    std::cout << "Digita una palabra: ";
    std::cin.getline(str_2, 25, '\n');

    my_strupr(str_1);
    my_strupr(str_2);

    if (strcmp(str_1, str_2) == 0)
    {
        std::cout << "Son iguales" << std::endl;
    }
    else
    {
        std::cout << "Son diferentes" << std::endl;
    }

    return 0;

}