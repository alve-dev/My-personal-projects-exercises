#include <stdio.h>

void collatz(int n);

int steps = 0;

int main(void)
{
    
    collatz(1);
    printf("Steps: %i\n", steps);
    steps = 0;
    collatz(2);
    printf("Steps: %i\n", steps);
    steps = 0;
    collatz(3);
    printf("Steps: %i\n", steps);
    steps = 0;
    collatz(4);
    printf("Steps: %i\n", steps);
    steps = 0;
    collatz(5);
    printf("Steps: %i\n", steps);
    steps = 0;
    collatz(6);
    printf("Steps: %i\n", steps);
    steps = 0;
    collatz(7);
    printf("Steps: %i\n", steps);
    steps = 0;
    collatz(8);
    printf("Steps: %i\n", steps);
    steps = 0;
    collatz(15);
    printf("Steps: %i\n", steps);
    steps = 0;
    collatz(27);
    printf("Steps: %i\n", steps);
    steps = 0;
    collatz(50);
    printf("Steps: %i\n", steps);
}

void collatz(int n)
{
    
    if (n == 1)
        return; 
    else if (n % 2 == 0)
    {
        steps++;
        collatz(n/2);
    }
    else if (n % 2 != 0)
    {
        steps++;
        collatz(3*n+1);
    }
    return;
}