#include "main.h"

/**
 * print_binary - Prints the binary representation of a number.
 * @n: The number to print in binary.
 */
void print_binary(unsigned long int n)
{
	int i, marker = 0;

	if (n == 0)
	{
		_putchar('0');
		return;
	}

	for (i = sizeof(unsigned long int) * 8 - 1; i >= 0; i--)
	{
		unsigned long int mask = 1UL << i;

		if (n & mask)
		{
			_putchar('1');
			marker = 1;
		}
		else if (marker)
		{
			_putchar('0');
		}
	}
}
