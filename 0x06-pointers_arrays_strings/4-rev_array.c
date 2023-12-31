#include "main.h"
/**
 * reverse_array - reverses the content of an array of integers.
 * @a : array to reverse
 * @n : number of elements
 *
 * Return: reversed array
 */
void reverse_array(int *a, int n)
{
	int i = 0;
	int j = n - 1;

	while (i < j)
	{
		int temp = a[i];

		a[i] = a[j];
		a[j] = temp;
		i++;
		j--;
	}
}
