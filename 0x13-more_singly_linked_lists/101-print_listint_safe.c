#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t list safely.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *walker = head, *runner = head;
	size_t count = 0;

	while (walker && runner && runner->next)
	{
		printf("[%p] %d\n", (void *)walker, walker->n);
		count++;
		walker = walker->next;
		runner = runner->next->next;
		if (walker == runner)
		{
			walker = head;
			while (walker != runner)
			{
				count++;
				printf("[%p] %d\n", (void *)walker, walker->n);
				walker = walker->next;
				runner = runner->next;
			}
			walker = walker->next;
			while (walker != runner)
			{
				count++;
				printf("[%p] %d\n", (void *)walker, walker->n);
				walker = walker->next;
			}

			printf("-> [%p] %d\n", (void *)walker, walker->n);
			return (count);
		}
	}
	while (walker)
	{
		printf("[%p] %d\n", (void *)walker, walker->n);
		count++;
		walker = walker->next;
	}
	return (count);
}
