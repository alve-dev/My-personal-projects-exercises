// Crear un vector dinamico que pueda agregar y eliminar elementos

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *array;
    size_t capacity;
    size_t size;

} vector;

// Metodos de mi vector dinamico
vector *create_vector();
void push(vector **vec, int element);
void pop(vector *vec);
int get(vector *vec, size_t index);
void clear(vector *vec);

int main(void)
{
    vector *list = create_vector();
    if (list == NULL) { return 1; }

    push(&list, 1);
    push(&list, 2);
    push(&list, 3);
    push(&list, 4);
    push(&list, 5);
    push(&list, 6);
    push(&list, 7);
    push(&list, 8);

    for (size_t i = 0; i < 9; i++)
    {
        printf("%i\n", get(list, i));
    }

    clear(list);
    free(list);

    return 0;
}

vector *create_vector()
{
    vector *v = malloc(sizeof(vector));
    if (v == NULL) { return NULL; }

    v->array = malloc(sizeof(int) * 4);
    v->capacity = 4;
    v->size = 0;

    return v;
}

static void resize(vector **vec)
{
    int *temp = realloc((*vec)->array, sizeof(int) * ((*vec)->capacity << 1));
    if (temp == NULL) 
    {
        perror("Error de memoria: en line 59");
        exit(EXIT_FAILURE);
    }
    
    (*vec)->array = temp; 
    (*vec)->capacity = (*vec)->capacity << 1;
}

static double load_factor(vector *vec)
{
    return (double)vec->size / vec->capacity;
}

void push(vector **vec, int element)
{
    if (load_factor(*vec) >= 0.75)
    {
        resize(vec);
    }

    (*vec)->array[(*vec)->size] = element;
    (*vec)->size++;
}

void pop(vector *vec)
{
    vec->size--;
}

int get(vector *vec, size_t index)
{
    if (index == vec->size)
    {
        perror("IndexError: Intento de acceso a un elemento por indice incorrecto.");
        exit(EXIT_FAILURE);
    }

    return vec->array[index];
}

void clear(vector *vec)
{
    free(vec->array);
    vec->size = 0;
}


