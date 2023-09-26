#include "lists.h"

/**
 * find_listint_loop - Finds the loop in a linked list.
 * @head: A pointer to the head of the list.
 * Return: The address of the node where the loop starts,
 * or NULL if there is no loop.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *i = head;
	listint_t *j = head;

	while (i != NULL && j != NULL && j->next != NULL)
	{
		i = i->next;
		j = j->next->next;

		if (i == j)
		{
			i = head;

			while (i != j)
			{
				i = i->next;
				j = j->next;
			}

			return (i);
		}
	}

	return (NULL);
}
