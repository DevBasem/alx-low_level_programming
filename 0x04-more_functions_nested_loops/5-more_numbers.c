#include "main.h"
/**
 * more_numbers - prints 10 times the numbers, from 0 to 14
 *
 * Return: numbers
 */
void more_numbers(void)
{
	int i;
	int j;

	for (i = 0; i <= 14; i++)
	{
		for (j = 0; j <= 9; j++)
		{
		_putchar((i > 9) ? (i / 10) + 48 : i + 48);
		_putchar((i > 9) ? (i % 10) + 48 : '\0');
		}
		_putchar ('\n');
	}
}
