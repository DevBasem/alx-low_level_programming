#include "main.h"
/**
 * print_number - prints an integer.
 * @n : the number to print.
 *
 * Return: a number.
 */
void print_number(int n)
{
	int x;

	if (n > 0)
	{
		if (n > 9 && n <= 99)
		{
			_putchar((n / 10) + 48);
			_putchar((n % 10) + 48);
		}
		if (n > 99 && n <= 999)
		{
			_putchar((n / 100) + 48);
			_putchar((n / 10) % 10 + 48);
			_putchar((n % 10) + 48);
		}
		if (n > 999 && n <= 9999)
		{
			_putchar((n / 1000) + 48);
			_putchar((n / 100) % 10 + 48);
			_putchar((n / 10) % 10 + 48);
			_putchar((n % 10) + 48);
		}
	}
	if (n < 0)
	{
		x = -n;
		if (n < -9 && n >= -99)
		{
			_putchar(45);
			_putchar((x / 10) + 48);
			_putchar((x % 10) + 48);
		}
		if (n < -99 && n <= -999)
		{
			_putchar(45);
			_putchar((x / 100) + 48);
			_putchar((x / 10) % 10 + 48);
			_putchar((x % 10) + 48);
		}
		if (n < -999 && n >= -9999)
		{
			_putchar(45);
			_putchar((x / 1000) + 48);
			_putchar((x / 100) % 10 + 48);
			_putchar((x / 10) % 10 + 48);
			_putchar((x % 10) + 48);
		}
	}
	if (n == 0)
	{
		_putchar(48);
	}
}
