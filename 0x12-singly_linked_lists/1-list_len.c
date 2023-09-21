#include "lists.h"

/**
 * print_list - returns the number of elements in a linked list_t list.
 * @h: elements list.
 *
 * Return: number of nodes.
 */
size_t list_len(const list_t *h)
{
	size_t i = 0;

	while (h != NULL)
	{
		h = h->next;
		i++;
	}
	return (i);
}
