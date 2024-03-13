#include <stdio.h>
#include "search_algos.h"

int binary_search_helper(int *array, size_t low, size_t high, int value);
void print_array(int *array, size_t low, size_t high);

/**
 * exponential_search - searches for a value in a sorted array of integers
 *                       using the Exponential search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in the array
 * @value: value to search for
 *
 * Return: first index where value is located, or -1 if not found or array is
 *         NULL
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t bound = 1;
	size_t low, high;

	if (array == NULL || size == 0)
		return (-1);

	while (bound < size && array[bound] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
		bound *= 2;
	}

	low = bound / 2;
	high = bound < size - 1 ? bound : size - 1;
	printf("Value found between indexes [%lu] and [%lu]\n", low, high);
	return (binary_search_helper(array, low, high, value));
}

/**
 * binary_search_helper - recursively searches for a value in a sorted array
 *                        of integers using the Binary search algorithm
 * @array: pointer to the first element of the array to search in
 * @low: index of the first element in the array
 * @high: index of the last element in the array
 * @value: value to search for
 *
 * Return: index of value if found, -1 otherwise
 */
int binary_search_helper(int *array, size_t low, size_t high, int value)
{
	size_t mid;

	if (low <= high)
	{
		mid = (low + high) / 2;
		print_array(array, low, high);
		if (array[mid] == value)
			return (mid);
		else if (array[mid] < value)
			return (binary_search_helper(array, mid + 1, high, value));
		else
			return (binary_search_helper(array, low, mid - 1, value));
	}
	return (-1);
}

/**
 * print_array - prints the elements of an array within a range
 * @array: pointer to the first element of the array
 * @low: index of the first element to print
 * @high: index of the last element to print
 */
void print_array(int *array, size_t low, size_t high)
{
	printf("Searching in array: ");
	while (low <= high)
	{
		printf("%d", array[low]);
		if (low < high)
			printf(", ");
		else
			printf("\n");
		low++;
	}
}
