//Libraries and macros
#include <stdio.h>
#include <stdlib.h>

//Prototypes

int main(void)
{
    int n;
    printf("Cuantos numeros ingresaras?: ");
    scanf("%d", &n);

    int *numbers = malloc(n * sizeof(int));
    if (numbers == NULL)
    {
        printf("MemoryAllocError in line 13\n");
        return 1;
    }

    int i = 0;
    do
    {
        printf("\nDigita un numero: ");
        scanf("%d", numbers+i);
        i++;
    } while (i < n);

    for (i = 0; i < n; i++)
    {
        printf("%d\n", *(numbers+i));
    }
    free(numbers);
    numbers = NULL;
    
    return 0;
}