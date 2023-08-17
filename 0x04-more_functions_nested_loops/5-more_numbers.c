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
	int dblNum;

	for (j = 0; j <= 9; j++)
	{
		for (i = 0; i <= 14; i++)
		{
		dblNum = i;
		if (i > 9)
		{
		_putchar(49);
		dblNum = i % 10;
		}
		_putchar (dblNum + 48);
		}
		_putchar ('\n');
	}
}
