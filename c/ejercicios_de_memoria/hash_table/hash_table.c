// Hash table in c

#include <stdio.h>

typedef struct node
{
    int data;
    struct node * next;
} node;

typedef struct
{
    char *key;
    node *values;
} table;

//Metodos de la hash table
void insert();
void search();
void free_table();



int main(void)
{

}