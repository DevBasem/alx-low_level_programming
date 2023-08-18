#include "main.h"
/**
 * print_number - prints an integer.
 * @n : the number to print.
 *
 * Return: a number.
 */
void print_number(int n)
{
	int divisor = 1000;
	int leading_zeros = 1;

	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}
	while (divisor > 0)
		{
		int digit = n / divisor;

		n %= divisor;
		divisor /= 10;
		if (digit != 0 || !leading_zeros)
		{
			_putchar(digit + '0');
			leading_zeros = 0;
		}
	}
	if (leading_zeros)
	{
		_putchar('0');
	}
}
