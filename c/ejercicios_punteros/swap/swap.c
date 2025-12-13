//Libraries
#include <stdio.h>

//Prototypes
void swap(int *a, int *b);

int main(void)
{
    int x;
    printf("Digita un numero: ");
    scanf("%d", &x);

    int y;
    printf("Digita otro numero: ");
    scanf("%d", &y);

    swap(&x, &y);

    printf("X: %d\n", x);
    printf("Y: %d", y);

    return 0;
}

void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
    return;
}
