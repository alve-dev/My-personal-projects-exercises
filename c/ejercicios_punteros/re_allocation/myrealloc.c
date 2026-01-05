//2. Escribe tu propia versión de realloc que solo acepte expansión.

#include <stdio.h>
#include <stdlib.h>

void *myrealloc(void *ptr, size_t size);

int main(void)
{
    int *number = malloc(sizeof(int) * 1);
    if (number == NULL) {return 1;}
    int *numbers = (int *)myrealloc(number, sizeof(int) * 3);

    numbers[0] = 5;
    numbers[1] = 10;
    numbers[2] = 15;

    printf("%i\n", numbers[2]);
    free(number);
    free(numbers);
    return 0;
}

void *myrealloc(void *ptr, size_t size)
{
    void *cp_ptr = malloc(size);
    if (cp_ptr == NULL) {return NULL;}

    if (size != 0)
    {
        return cp_ptr;
    }
    else
    {
        free(ptr);
        return NULL;
    }

}