#include "main.h"

/**
 * print_number - Prints an integer using _putchar function
 * @n: The integer to be printed
 */
void print_number(int n)
{
	int divisor = 1;
	int temp;

	if (n < 0)
	{
		_putchar('-');
		n *= -1;
	}

	temp = n;
	while (temp / 10 != 0)
	{
		divisor *= 10;
		temp /= 10;
	}

	while (divisor != 0)
	{
		_putchar((n / divisor) + '0');
		n %= divisor;
		divisor /= 10;
	}
}
