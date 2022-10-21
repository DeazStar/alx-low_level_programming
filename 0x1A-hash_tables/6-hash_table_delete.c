#include "hash_tables.h"


/**
 * hash_table_delete - Deletes a hash table.
 * @ht: A pointer to a hash table.
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *next;
	hash_node_t *tmp;
	unsigned long int i;

	if (ht == NULL)
		return;

	for (i = 0; i < ht->size; i++)
	{
		if (ht->array[i] != NULL)
		{
			next = ht->array[i];

			while (next != NULL)
			{
				tmp = next->next;
				free(next->key);
				free(next->value);
				free(next);
				next = tmp;
			}
		}
	}

	free(ht->array);
	free(ht);
}
