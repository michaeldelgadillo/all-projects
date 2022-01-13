// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <ctype.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 676;

// Number of words in Dictionary
unsigned int M = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    unsigned int j = hash(word);

    node *tmp[N];
    tmp[j] = table[j];
    while (tmp[j] != NULL)
    {
        if (strcasecmp(tmp[j]->word, word) == 0)
        {
            return true;
        }
        else
        {
            tmp[j] = tmp[j]->next;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{

    int k = strlen(word);
    int total = 0;

    unsigned long hash = 5381;
    int i = 0;

    while (i < k)
    {
        hash = ((hash << 5) + hash) + tolower(word[i]); /* hash * 33 + word */
        i++;
    }

    i = 0;
    int add_Letters = 0;
    while (i < 4 && word[i])
    {
        add_Letters += tolower(word[i]);
        i++;
    }

    hash %= add_Letters;

    if (hash > N)
    {
        hash %= N;
    }
    return hash;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    char text[LENGTH];

    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    node *n = NULL;
    while(fscanf(file, "%s", text) != EOF)
    {
        n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        strcpy(n->word, text);

        // Returns hash value for instant insertion
        int j = hash(text);

        // Inserts new word at the beginging of location J
        n->next = table[j];
        table[j] = n;
        M++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return M;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    int i = 0;
    node *tmp[N];

    while(i < N)
    {
        while (table[i] != NULL)
        {
                tmp[i] = table[i]->next;
                free(table[i]);
                table[i] = tmp[i];
        }
        i++;
    }
    return true;
}