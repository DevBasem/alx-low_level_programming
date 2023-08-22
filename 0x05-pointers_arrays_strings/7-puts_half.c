#include "main.h"
/**
 * puts_half - prints half of a string, followed by a new line.
 * @str : string to print
 *
 * Return: string
 */
void puts_half(char *str)
{
	int j;

	if ((strlen(str) % 2) == 0)
	{
		for (j = strlen(str) / 2; str[j] != '\0'; j++)
		{
			_putchar(str[j]);
		}
	}
	else
	{
		for (j = ((strlen(str) - 1) / 2) + 1; str[j] != '\0'; j++)
		{
			_putchar(str[j]);
		}
	}
	_putchar('\n');
}
