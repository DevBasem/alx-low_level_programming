#include "main.h"
/**
 * *print_number - prints an integer.
 * @n: number to print
 *
 * Return: printed number
 */
void print_number(int n)
{
	int divisor = 1;
	int num = n;

	if (n < 0)
	{
		_putchar('-');
		num = -num;
	}
	else if (n == 0)
	{
		_putchar('0');
		return;
	}

	while (num / divisor > 0)
	{
		divisor *= 10;
	}

	divisor /= 10;

	while (divisor > 0)
	{
		int digit = num / divisor;

		_putchar(digit + '0');
		num %= divisor;
		divisor /= 10;
	}
}

