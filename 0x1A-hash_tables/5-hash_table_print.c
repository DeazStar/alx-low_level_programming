#include "hash_tables.h"

/**
 * hash_table_print - Print a hash table
 * @ht: a pointer to the hash table
 *
 * Return: Nothing
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned int i;
	hash_node_t *head_node;
	int flag = 0;

	if (ht == NULL)
		return;

	printf("{");

	for (i = 0; i < ht->size; i++)
	{
		if (ht->array[i] != NULL)
		{
			if (flag == 1)
				printf(", ");

			head_node = ht->array[i];

			while (head_node != NULL)
			{
				printf("'%s': '%s'", head_node->key, head_node->value);
				head_node = head_node->next;
				if (head_node != NULL)
				{
					printf(", ");
				}
			}

			flag = 1;
		}
	}
	printf("}\n");
}
