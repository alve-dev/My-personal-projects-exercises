#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *name;
    int age;
} person;

person *create_person(const char *name, int age);
void destroy_person(person *ptr_person);
char *my_strdup(const char *s);

int main(void)
{
    int n = 5;
    person **personas = malloc(sizeof(person *) * n);
    personas[0] = create_person("Alejandro", 16);
    personas[1] = create_person("Santiago", 14);
    personas[2] = create_person("Nicolas", 10);
    personas[3] = create_person("Juan", 10);
    personas[4] = create_person("Salome", 8);

    for (int i = 0; i < n; i++)
    {
        printf("NOMBRE: %s\n", personas[i]->name);
        printf("EDAD: %i\n", personas[i]->age);
        printf("\n");
    }

    for (int i = 0; i < n; i++)
    {
        destroy_person(personas[i]);
    }
    free(personas);
    
    return 0;


}

person *create_person(const char *name, int age)
{
    person *p = malloc(sizeof(person));
    if (p == NULL)
    {
        return NULL;
    }
    p->name = my_strdup(name);
    if (p->name == NULL)
    {
        free(p);
        return NULL
    }
    p->age = age;
    return p;
}

void destroy_person(person *ptr_person)
{
    free(ptr_person->name);
    free(ptr_person);
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