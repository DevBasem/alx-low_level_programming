#include <stdio.h>
#include "search_algos.h"

/**
 * advanced_binary - searches for a value in a sorted array of integers
 * using the advanced binary search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in the array
 * @value: value to search for
 *
 * Return: index where value is located, or -1 if not found or array is NULL
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t left, right;
	int mid;

	if (array == NULL || size == 0)
		return (-1);

	left = 0;
	right = size - 1;

	while (left <= right)
	{
		print_array(array, left, right);
		mid = (left + right) / 2;
		if (array[mid] < value)
			left = mid + 1;
		else if (array[mid] > value)
			right = mid;
		else
		{
			if (mid == 0 || array[mid - 1] != value)
				return (mid);
			right = mid;
		}
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
