#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table.
 * @ht: A pointer to a hash table.
 *
 * Return: Nothing
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *tmp;
	hash_node_t *next = NULL;
	unsigned int i;

	if (ht == NULL)
		return;

	for (i = 0; i < ht->size; i++)
	{
		if (ht->array[i] == NULL)
		{
			continue;
		}
		else
		{
			tmp = ht->array[i];

			while (tmp != NULL)
			{
				next = tmp;
				tmp = tmp->next;
				free(next->key);
				free(next->value);
				free(next);
				next = NULL;
			}
			ht->array[i] = NULL;
		}
	}

	free(ht->array);
	free(tmp);
	free(ht);
}
