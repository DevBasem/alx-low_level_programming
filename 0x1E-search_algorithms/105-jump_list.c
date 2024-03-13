#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "search_algos.h"

void free_list(listint_t *list);

/**
 * create_list - Creates a single linked list
 *
 * @array: Pointer to the array to use to fill the list
 * @size: Size of the array
 *
 * Return: A pointer to the head of the created list (NULL on failure)
 */
listint_t *create_list(int *array, size_t size)
{
	listint_t *list;
	listint_t *node;

	list = NULL;
	while (array && size--)
	{
		node = malloc(sizeof(*node));
		if (!node)
		{
			free_list(list);
			return (NULL);
		}
		node->n = array[size];
		node->index = size;
		node->next = list;
		list = node;
	}
	return (list);
}

/**
 * free_list - Deallocates a singly linked list
 *
 * @list: Pointer to the linked list to be freed
 */
void free_list(listint_t *list)
{
	listint_t *node;

	if (list)
	{
		node = list->next;
		free(list);
		free_list(node);
	}
}

/**
 * print_list - Prints the content of a listint_t
 *
 * @list: Pointer to the head of the list
 */
void print_list(const listint_t *list)
{
	printf("List :\n");
	while (list)
	{
		printf("Index[%lu] = [%d]\n", list->index, list->n);
		list = list->next;
	}
	printf("\n");
}

/**
 * jump_list - Searches for a value in a sorted list of integers
 * using Jump search
 *
 * @list: Pointer to the head of the list to search in
 * @size: Number of nodes in the list
 * @value: Value to search for
 *
 * Return: Pointer to the node where value is located, or NULL if not found
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t step = sqrt(size);
	listint_t *prev = NULL;
	listint_t *current = NULL;
	size_t i;

	if (!list || size == 0)
		return (NULL);

	do {
		prev = list;
		current = list;
		for (i = 0; current->next && i < step; i++)
			current = current->next;
		list = current;
		printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
	} while (list->index < size - 1 && list->n < value);

	printf("Value found between indexes [%lu] and [%lu]\n",
			prev->index, list->index);

	for (; prev && prev->index <= list->index; prev = prev->next)
	{
		printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
		if (prev->n == value)
			return (prev);
	}

	return (NULL);
}
