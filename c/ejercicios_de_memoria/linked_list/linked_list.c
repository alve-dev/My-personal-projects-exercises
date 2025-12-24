#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node_int
{
    int data;
    struct node_int *next;
} node_int;

typedef struct node_str
{
    char *data;
    struct node_str *next;
} node_str;

typedef struct
{
    node_int *head;
    size_t len;
} list;

//methods linked list
//void printls(node *list, const char newline);
void insert(list *list, int n);
bool search(node *list, int n);
void delete(node *list, int n);
int len_list(list *list);
void free_list(node *list);

int main(void)
{
    list *list_numbers = malloc(sizeof(list));
    if (list_numbers != NULL)
    {
        list_numbers->len = 0;
        list_numbers->head->next = NULL
    }

    insert(list_numbers, 0);

    //printls(list_numbers, '\n');

    free_list(list_numbers);
    return 0;
}

/*
void printls(list *list, const char newline)
{
    if (list->next == NULL)
    {
        printf("%i", list->data);
        if(newline == '\n'){printf("\n");}
    }
    else
    {
        printf("%i", list->head);
        if(newline == '\n'){printf("\n");}
        printls(list->next, newline);
    }
}*/

void insert(list *list, int n)
{
    if (list->len == 0)
    {
        list->head->data = n;
        list->len++;
    }
    else
    {
        node_int *new_element = malloc(sizeof(node_int));
        new_element->data = n;
        new_element->next = list->head;
        list->head = new_element;
        list->len++;
    }
}

int len_list(list *list)
{
    return list->len;
}

bool search(node *list, int n)
{
    if (list->data == n)
    {
        return true;
    }
    else
    {
        if (list->next == NULL)
        {
            return false;
        }

        return search(list->next, n);
    }
}

void delete(node *list, int n)
{
    if (list->data == n)
    {
        free(list);
        list = NULL;
    }
    else
    {
        delete(list->next, n);
    }
}

void free_list(list *list)
{
    if (list->next == NULL)
    {
        delete(list, list->data);
    }
    else
    {
        free_list(list->next);
        delete(list, list->data);
    }
}

