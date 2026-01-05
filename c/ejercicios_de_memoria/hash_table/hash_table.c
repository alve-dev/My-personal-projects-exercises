// Hash table in c

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct entry
{
    char *key;
    char *value;
    struct entry *next;
} entry;

typedef struct
{
    entry **buckets;
    size_t capacity;
    size_t size;
} table;

//Prototipos de los metodos
table *hs_create(size_t capacity);
static void resize(table **dict);
static unsigned int hash(const char *key, size_t capacity);
void hs_insert(table **hs_table, const char *key, const char *value);
char *hs_search(table *hs_table, const char *key);
void hs_delete(table *dict, const char *key);
void hs_clear(table *dict);

int main(void)
{
    table *dict = hs_create(16);
    hs_insert(&dict, "var", "TokenType.VAR");
    hs_insert(&dict, "let", "TokenType.LET");
    hs_insert(&dict, "int", "TokenType.INT");
    hs_insert(&dict, "float", "TokenType.FLOAT");
    hs_insert(&dict, "string", "TokenType.STRING");
    hs_insert(&dict, "bool", "TokenType.BOOL");
    hs_insert(&dict, "if", "TokenType.IF");
    hs_insert(&dict, "elif", "TokenType.ELIF");
    hs_insert(&dict, "else", "TokenType.ELSE");
    hs_insert(&dict, "and", "TokenType.AND");
    hs_insert(&dict, "or", "TokenType.OR");
    hs_insert(&dict, "not", "TokenType.NOT");
    hs_insert(&dict, "True", "TokenType.TRUE");
    hs_insert(&dict, "False", "TokenType.FALSE");

    printf("%s\n", hs_search(dict, "var"));
    printf("%s\n", hs_search(dict, "let"));
    printf("%s\n", hs_search(dict, "int"));
    printf("%s\n", hs_search(dict, "float"));
    printf("%s\n", hs_search(dict, "string"));
    printf("%s\n", hs_search(dict, "bool"));
    printf("%s\n", hs_search(dict, "if"));
    printf("%s\n", hs_search(dict, "elif"));
    printf("%s\n", hs_search(dict, "else"));
    printf("%s\n", hs_search(dict, "and"));
    printf("%s\n", hs_search(dict, "or"));
    printf("%s\n", hs_search(dict, "not"));
    printf("%s\n", hs_search(dict, "True"));
    printf("%s\n", hs_search(dict, "False"));


    hs_clear(dict);
    free(dict);
    return 0;
}

//Metodos de la hash table
static inline double load_factor(const table *hs)
{
    return (double)hs->size / hs->capacity;
}

table *hs_create(size_t capacity)
{
    table *ht = malloc(sizeof(table));
    if (!ht) return NULL;

    ht->buckets = calloc(capacity, sizeof(entry *));
    if (!ht->buckets)
    {
        free(ht);
        return NULL;
    }

    ht->capacity = capacity;
    ht->size = 0;
    return ht;

}

static unsigned int hash(const char *key, size_t capacity)
{
    unsigned int hash = 5381;
    while (*key)
    {
        hash = ((hash << 5) + hash) + (unsigned char)*key;
        key++;
    }
    return hash % capacity;
}

static void resize(table **dict)
{
    table *old = *dict;
    table *new_dict = hs_create(old->capacity << 1);

    for (size_t i = 0; i < old->capacity; i++)
    {
        entry *current = old->buckets[i];
        while (current != NULL)
        {
            entry *next = current->next;
            unsigned int new_hash = hash(current->key, new_dict->capacity);
            current->next = new_dict->buckets[new_hash];
            new_dict->buckets[new_hash] = current;
            new_dict->size++;
            current = next;
        }
    }
    free(old->buckets);
    free(old);

    *dict = new_dict;
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

void hs_insert(table **dict, const char *key, const char* value)
{
    if (load_factor(*dict) >= 0.75)
    {
        resize(dict);
    }

    unsigned int hash_key = hash(key, (*dict)->capacity);

    for (entry *e = (*dict)->buckets[hash_key]; e != NULL; e = e->next)
    {
        if (strcmp(e->key, key) == 0)
        {
            free(e->value);
            e->value = my_strdup(value);
            return;
        }
    }

    entry *new = malloc(sizeof(entry));
    if (new == NULL)
    {
        return;
    }

    new->key = my_strdup(key);
    new->value = my_strdup(value);
    
    if ((*dict)->buckets[hash_key] == NULL)
    {
        new->next = NULL;
    }
    else
    {
        new->next = (*dict)->buckets[hash_key];
    }

    (*dict)->buckets[hash_key] = new;
    (*dict)->size++;
}

char *hs_search(table *dict, const char *key)
{
    unsigned int hash_key = hash(key, dict->capacity);

    for (entry *current = dict->buckets[hash_key]; current != NULL; current = current->next)
    {
        if (strcmp(current->key, key) == 0)
        {
            return current->value;
        }
    }

    return NULL;
}

void hs_delete(table *dict, const char *key)
{
    unsigned int hash_key = hash(key, dict->capacity);

    if (dict->buckets[hash_key] == NULL)
    {
        return;
    }

   entry *current = dict->buckets[hash_key];
   entry *prev = NULL;

   //buscar nodo
   while (current != NULL && strcmp(current->key, key) != 0)
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
        dict->buckets[hash_key] = current->next;
   }
   else
   {
        prev->next = current->next;
   }

   free(current->key);
   free(current->value);
   free(current);
   dict->size--;
}

void hs_clear(table *dict)
{
    if (dict->capacity == 0 || dict->size == 0)
    {
        return;
    }
    else
    {
        for (size_t i = 0; i < dict->capacity; i++)
        {
            entry *current = dict->buckets[i];
            while (current != NULL)
            {
                entry *next = current->next;
                free(current->key);
                free(current->value);
                free(current);
                current = next;
            }
        }
    }

    free(dict->buckets);
    dict->buckets = NULL;
    dict->size = 0;
}

