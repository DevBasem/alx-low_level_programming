#include "main.h"
/**
 * _puts - prints a string, followed by a new line, to stdout.
 * @str : string to print
 *
 * Return: string
 */
void _puts(char *str)
{
	int length = 0;

	while (str[length] != '\0')
	{
		_putchar(str[length]);
		length++;
	}
	_putchar('\n');
}
