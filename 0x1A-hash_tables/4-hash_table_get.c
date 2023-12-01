#include "hash_tables.h"
#include <string.h>

/**
 * hash_table_get - Retrieves a value associated with a key
 * @ht: The hash table to look into
 * @key: The key to look for
 *
 * Return: The value associated with the key, or NULL if key couldn't be found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *current = NULL;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	/* Get the index where the key should be stored */
	index = key_index((unsigned char *)key, ht->size);

	/* Search for the key in the list at the computed index */
	current = ht->array[index];
	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
			return (current->value);
		current = current->next;
	}

	/* Key not found */
	return (NULL);
}
