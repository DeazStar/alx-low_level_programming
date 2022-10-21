#include "hash_tables.h"

/**
 * key_index - gives the index of a key
 * @key: the key
 * @size: the size of the array of hash table
 *
 * Return: the index
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int idx;

	idx = hash_djb2(key);

	idx = idx % size;

	return (idx);
}
