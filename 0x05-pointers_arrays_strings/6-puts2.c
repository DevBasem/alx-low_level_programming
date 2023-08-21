#include "main.h"
/**
 * _puts - prints every other character of a string,
 * starting with the first character, followed by a new line.
 * @str : string to print
 *
 * Return: string
 */
void puts2(char *str)
{
	int length = 0;

	while (str[length] != '\0')
	{
		_putchar(str[length]);
		length += 2;
	}
	_putchar('\n');
}
