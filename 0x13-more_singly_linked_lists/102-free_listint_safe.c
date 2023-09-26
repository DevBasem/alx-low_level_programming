#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t list.
 * @h: A pointer to a pointer to the head of the list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *current = *h, *temp;
	size_t size = 0;

	while (current)
	{
		size++;
		if (current->next >= current)
		{
			temp = current;
			current = current->next;
			free(temp);
			break;
		}
		temp = current;
		current = current->next;
		free(temp);
	}

	*h = NULL;
	return (size);
}
