#include "main.h"
/**
 * print_diagsums - prints the chessboard.
 * @a: chess array.
 * @size: chess array.
 *
 * Return: chessboard printed.
 */
void print_diagsums(int *a, int size)
{
	int i;
	int sum1 = 0;
	int sum2 = 0;

	/*for (i = 0; i < size * size; i++)
	{
		if (i == 0 || i % (size + 1) == 0)
		{
			sum1 += a[i];
			j++;
		}
		if (i == (size - 1) || (i % (size - 1) == 0 && j < size))
		{
			sum2 += a[i];
		}
	}*/
	    for (i = 0; i < size; i++) {
        sum1 += a[i * size + i];
        sum2 += a[i * size + (size - i - 1)];
    }
	printf("%d, %d\n", sum1, sum2);
}
