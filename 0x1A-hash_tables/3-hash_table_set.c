#include "hash_tables.h"

/**
 * hash_table_set - Add or update an element to the hash table
 * @ht: The pointer to the hash table
 * @key: The key to add
 * @value: The value associated with key
 *
 * Return: if Success - 1 otherwise - 0
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
    hash_node_t *new;
    hash_node_t *head_node;
    unsigned long int idx, i;

    if (ht == NULL || key == NULL || value == NULL || *key == '\0')
        return (0);

    new = malloc(sizeof(hash_node_t));

    if (new == NULL)
        return (0);

    idx = key_index((const unsigned char *)key, ht->size);

    for (i = idx; ht->array[i]; i++)
	{
		if (strcmp(ht->array[i]->key, key) == 0)
		{
			free(ht->array[i]->value);
			ht->array[i]->value = strdup(value);
			return (1);
		}
	}

    new->key = strdup(key);
    new->value = strdup(value);
    new->next = NULL;

    if (ht->array[idx] != NULL)
    {
        head_node = ht->array[idx];
        new->next = head_node;
    }

    ht->array[idx] = new;

    return (1);
}
