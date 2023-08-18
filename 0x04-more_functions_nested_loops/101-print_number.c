#include "main.h"
/**
 * print_number - prints an integer.
 * @n : the number to print.
 *
 * Return: a number.
 */
void print_number(int n)
{
	unsigned int pN = n;

	if (n < 0)
	{
		_putchar('-');
		pN = -pN;
	}
	if ((pN / 10) > 0)
		print_number(pN / 10);
	_putchar((pN % 10) + 48);
}
