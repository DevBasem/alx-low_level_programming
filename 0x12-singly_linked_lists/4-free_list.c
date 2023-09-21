#include "lists.h"

/**
 * free_list - frees a list_t list..
 * @head: elements list.
 *
 * Return: Nothing.
 */
void free_list(list_t *head)
{
	while (head != NULL)
	{
		list_t *temp = head;

		head = head->next;

		free(temp->str);
		free(temp);
	}
}
