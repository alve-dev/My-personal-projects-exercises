//5. Hcaer programa que compruebe si una palabra en polindroma o no

#include <iostream>
#include <cstring>
#include <algorithm>

char* my_strrev(char* str) {
    if (!str) return NULL;

    int i = 0;
    int j = strlen(str) - 1;
    char temp;
    
    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
    return str;
}

int main(void)
{
    using std::cout, std::cin, std::endl;

    std::string str;
    cout << "Digita una palabras: ";
    cin.getline(str, 25, '\n');

    std::string rstring;
    std::reverse(str, rstring);

    if (str == rstring)
    {
        cout << "La palabra es polindroma" << endl;
    }
    else
    {
        cout << "La palabra no es polindroma" << endl;
    }

    return 0;
}