#include "function_pointers.h"

/**
 * array_iterator - a call back function.
 * @array: array to be printed.
 * @size: the size of the arrary.
 * @action: the function used in the array.
 *
 * Return: Nothing.
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (array == NULL || action == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		action(array[i]);
	}
}
