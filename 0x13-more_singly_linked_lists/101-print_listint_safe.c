#include "lists.h"

/**
 * find_loop_length - Counts the number of unique nodes
 * in a looped listint_t linked list.
 * @head: A pointer to the head of the listint_t to check.
 *
 * Return: If the list is not looped - 0.
 */
size_t find_loop_length(const listint_t *head)
{
	const listint_t *slow_runner, *fast_runner;
	size_t nodes_count = 1;

	if (!head || !head->next)
		return (0);

	slow_runner = head->next;
	fast_runner = (head->next)->next;

	while (fast_runner)
	{
		if (slow_runner == fast_runner)
		{
			slow_runner = head;
			while (slow_runner != fast_runner)
			{
				nodes_count++;
				slow_runner = slow_runner->next;
				fast_runner = fast_runner->next;
			}

			slow_runner = slow_runner->next;
			while (slow_runner != fast_runner)
			{
				nodes_count++;
				slow_runner = slow_runner->next;
			}

			return (nodes_count);
		}

		slow_runner = slow_runner->next;
		fast_runner = (fast_runner->next)->next;
	}

	return (0);
}

/**
 * print_listint_safe - Prints a listint_t list safely.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nodes_count, index = 0;

	nodes_count = find_loop_length(head);

	if (nodes_count == 0)
	{
		for (; head != NULL; nodes_count++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}
	else
	{
		for (index = 0; index < nodes_count; index++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}

		printf("-> [%p] %d\n", (void *)head, head->n);
	}

	return (nodes_count);
}
