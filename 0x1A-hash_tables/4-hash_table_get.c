#include "hash_tables.h"

/**
 * hash_table_get - Retrive the value
 * @ht: A pointer to the hash table
 * @key: the key to get the value of
 *
 * Return: if key then value otherwise NULL
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *tmp;
	unsigned long int idx;

	idx = key_index((const unsigned char *)key, ht->size);
	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	if (ht->array[idx] == NULL)
		return (NULL);

	if (strcmp(ht->array[idx]->key, key) == 0)
		return (ht->array[idx]->value);

	tmp = ht->array[idx];

	while (tmp != NULL)
	{
		if (strcmp(tmp->key, key))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}
