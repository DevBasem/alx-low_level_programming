#include "search_algos.h"
#include <stdio.h>
#include <math.h>

/**
 * jump_list - Searches for a value in a sorted list of integers using
 *             the Jump search algorithm
 * @list: Pointer to the head of the list to search in
 * @size: Number of nodes in list
 * @value: Value to search for
 *
 * Return: Pointer to the first node where value is located,
 *         or NULL if value is not present or list is NULL
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	listint_t *current, *prev;
	size_t jump = sqrt(size), i, j;

	if (list == NULL)
		return (NULL);

	current = list;
	prev = NULL;

	while (current != NULL && current->n < value)
	{
		prev = current;
		for (i = 0; current->next != NULL && i < jump; i++)
			current = current->next;

		printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
			prev != NULL ? prev->index : 0, current->index);

	for (j = prev != NULL ? prev->index : 0; j <= current->index; j++)
	{
		printf("Value checked at index [%lu] = [%d]\n", j, current->n);
		if (current->n == value)
			return (current);
		current = current->next;
	}

	return (NULL);
}
