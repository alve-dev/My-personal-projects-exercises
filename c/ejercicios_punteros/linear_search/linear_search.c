//Libraries and macros
#define LEN_ARRAY 3
#include <stdio.h>

//Prototypes
int *search_value(int *first_element, int len_array, int value_searched);

int main(void)
{
    int array[LEN_ARRAY] = {1, 2, 3};
    int *ptr_first_value = &array[0];
    int *value = search_value(ptr_first_value, LEN_ARRAY, 4);
    if (value == NULL)
    {
        printf("El valor no existe\n");
    }
    else
    {
        printf("El valor si existe\n");
    }
    
    return 0;
}

int *search_value(int *ptr, int len_array, int value_searched)
{
    for (int *array_end = ptr + len_array; ptr < array_end; ptr++)
    {
        if (*ptr == value_searched)
        {
            return ptr;
        }
    }
    return NULL;
}