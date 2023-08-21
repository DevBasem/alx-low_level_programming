#include "main.h"
/**
 * print_rev - prints a string, in reverse, followed by a new line.
 * @s : string to print
 *
 * Return: rev string
 */
void print_rev(char *s)
{
	int i;

	for (i = strlen(s) - 1; i >= 0; i--)
	{
		_putchar(s[i]);
	}
	_putchar('\n');
}
