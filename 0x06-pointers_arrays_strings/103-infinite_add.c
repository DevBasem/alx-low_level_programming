#include "main.h"
/**
 * *infinite_add - function that adds two numbers.
 * @n1: number1
 * @n2: number2
 * @r: the buffer
 * @size_r: buffersize
 *
 * Return: added numbers
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len_n1 = strlen(n1), len_n2 = strlen(n2), carry = 0, idx_r = 0;
	int left, right;

	while (len_n1 > 0 || len_n2 > 0 || carry)
	{
		if (idx_r >= size_r - 1)
			return (0);

		if (len_n1 > 0)
			carry += n1[--len_n1] - '0';
		if (len_n2 > 0)
			carry += n2[--len_n2] - '0';

		r[idx_r++] = carry % 10 + '0';
		carry /= 10;
	}

	r[idx_r] = '\0';

	for (left = 0, right = idx_r - 1; left < right; left++, right--)
	{
		char temp = r[left];

		r[left] = r[right];
		r[right] = temp;
	}

	return (r);
}
