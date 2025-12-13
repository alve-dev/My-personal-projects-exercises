#include <stdio.h>
#include <stdlib.h> 

// Prototipo
int *clone_int(int *ptr_original);

int main(void)
{
    int numero = 50;
    int *copia_int;
    copia_int = clone_int(&numero);
    
    if (copia_int == NULL) // Es vital verificar esto siempre
    {
        printf("Error: Fallo de memoria.\n");
        return 1;
    }
    
    printf("Original: %i | Dir: %p\n", numero, (void *)&numero);
    // Imprime el valor usando *copia_int y la direccion con %p
    printf("Copia:    %i | Dir: %p\n", *copia_int, (void *)copia_int); 

    free(copia_int); // Libera la memoria del HEAP
    copia_int = NULL; // Evita el puntero colgante

    return 0;
}

int *clone_int(int *ptr_original)
{
    int *x; 
    x = malloc(sizeof(int));
    
    if (x == NULL) // Es vital verificar esto siempre
    {
        return NULL;
    }
    
    *x = *ptr_original; // COPIA EL VALOR AL HEAP
    return x;
}
