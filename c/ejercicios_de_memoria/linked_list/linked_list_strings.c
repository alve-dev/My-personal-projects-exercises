// Linked list of strings

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char *string;
    struct node *next;
} node;

typedef struct
{
    node *head;
    size_t len;
} list;

//metodos de list of strings
void insert(list *l, const char *s);
void delete(list *l, const char *s);
void clear(list *l);
bool search(list *l, const char *s);
size_t len(list *l);



int main(void)
{
    //init list of strings
    list *vector = malloc(sizeof(list));
    if (vector != NULL)
    {
        vector->head = NULL;
        vector->len = 0;
    }

    insert(vector, "alex");
    insert(vector, "santiago");
    insert(vector, "nicolas");
    insert(vector, "juan");
    insert(vector, "salome");
    delete(vector, "alex");
    delete(vector, "nicolas");

    for (node *cur = vector->head; cur != NULL; cur = cur->next)
    {
        printf("%s\n", cur->string);
    }
    printf("El tamaño de vector es %li\n", len(vector)),

    clear(vector);
    free(vector);

    return 0;


}

char *my_strdup(const char *s)
{
    char *dup_s = malloc(strlen(s) + 1);
    if (dup_s == NULL)
    {
        return NULL;
    }
    strcpy(dup_s, s);
    return dup_s;
}

void insert(list *l, const char *s)
{
    node *new = malloc(sizeof(node));
    new->string = my_strdup(s);
    new->next = l->head;
    l->head = new;
    l->len++;
}

void delete(list *l, const char *s)
{
    if (l->head == NULL)
   {
        return;
   }

   node *current = l->head;
   node *prev = NULL;

   //buscar nodo
   while (current != NULL && strcmp(current->string, s) != 0)
   {
        prev = current;
        current = current->next;
   }

   if (current == NULL)
   {
        return;
   }

   if (prev == NULL)
   {
        l->head = current->next;
   }
   else
   {
        prev->next = current->next;
   }

   free(current->string);
   free(current);
   l->len--;
}

void clear(list *l)
{
    node *current = l->head;
    while (current !=  NULL)
    {
        node *next = current->next;
        free(current->string);
        free(current);
        current = next;
    }

    l->head = NULL;
    l->len = 0;
}

bool search(list *l, const char *s)
{
    for (node *cur = l->head; cur != NULL; cur = cur->next)
    {
        if (strcmp(cur->string, s) == 0)
        {
            return true;
        }
    }

    return false;
}


size_t len(list *l)
{
    return l->len;
}