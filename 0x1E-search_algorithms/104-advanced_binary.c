#include <stdio.h>
#include "search_algos.h"

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

/**
 * recursive_advanced_binary - recursively searches for a value in a sorted
 *                              array of integers using the advanced binary
 *                              search algorithm
 * @array: pointer to the first element of the array to search in
 * @left: left index of the subarray to search in
 * @right: right index of the subarray to search in
 * @value: value to search for
 *
 * Return: index where value is located, or -1 if not found
 */
int recursive_advanced_binary(int *array, size_t left, size_t right, int value)
{
    size_t mid;
    int result;

    if (left > right)
        return (-1);

    print_array(array, left, right);

    mid = left + (right - left) / 2;

    if (array[mid] == value)
    {
        if (mid == 0 || array[mid - 1] != value)
            return (mid);
    }

    if (array[mid] >= value)
        result = recursive_advanced_binary(array, left, mid, value);
    else
        result = recursive_advanced_binary(array, mid + 1, right, value);

    return (result);
}

/**
 * advanced_binary - searches for a value in a sorted array of integers using
 *                   the advanced binary search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in the array
 * @value: value to search for
 *
 * Return: index where value is located, or -1 if not found or array is NULL
 */
int advanced_binary(int *array, size_t size, int value)
{
    if (array == NULL || size == 0)
        return (-1);

    return (recursive_advanced_binary(array, 0, size - 1, value));
}
