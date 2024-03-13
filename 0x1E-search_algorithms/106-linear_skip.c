#include "search_algos.h"
#include <stdio.h>
#include <math.h>

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: pointer to the head of the skip list to search in
 * @value: value to search for
 *
 * Return: pointer to the node where value is located, or NULL on failure
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current, *express;

	if (list == NULL)
		return (NULL);

	express = list->express;
	while (express)
	{
		printf("Value checked at index [%lu] = [%d]\n", 
				express->index, express->n);
		if (express->n >= value)
			break;
		current = express;
		express = express->express;
	}

	if (!express)
	{
		current = list;
		while (current->next)
			current = current->next;
		printf("Value found between indexes [%lu] and [%lu]\n", 
				current->index, current->index);
	}
	else
	{
		printf("Value found between indexes [%lu] and [%lu]\n", 
				current->index, express->index);
	}

	current = current->next;
	while (current)
	{
		printf("Value checked at index [%lu] = [%d]\n", 
				current->index, current->n);
		if (current->n == value)
			return (current);
		else if (current->n > value)
			break;
		current = current->next;
	}

	return (NULL);
}
