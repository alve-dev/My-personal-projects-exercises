#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *number_array = malloc(sizeof(int) * 5);
    int i = 0;
    do
    {
        printf("Digita un numero: ");
        scanf("%i", &number_array[i]);
        i++;
    } while (i < 5);
    
    for (i = 0; i < 5; i++)
    {
        printf("El numero es %i\n", number_array[i]);
    }
    free(number_array);
    
    return 0;

}