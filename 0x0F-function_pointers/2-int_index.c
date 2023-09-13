#include "function_pointers.h"

/**
 * int_index - a call back function.
 * @array: array to be printed.
 * @size: the size of the arrary.
 * @cmp: the function used to compare.
 *
 * Return: Nothing.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == NULL || cmp == NULL)
		return (-1);
	if (size <= 0)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]))
			return (i);
	}
	return (-1);
}
