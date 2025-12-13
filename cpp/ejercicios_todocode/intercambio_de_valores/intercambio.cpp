#include <iostream>

using namespace std;

int input(string prompt);

int main(void)
{
    int num_1 = input("Digita un numero: ");
    int num_2 = input("Digita otro numero: ");
    int aux = num_1;
    string name 
    num_1 = num_2;
    num_2 = aux;
    cout << "Numero 1: " << num_1 << endl;
    cout << "Numero 2: " << num_2 << endl;
    return 0;
}

int input_int(string prompt)
{
    int integer;
    cout << prompt; 
    cin >> integer;
    return integer;
}