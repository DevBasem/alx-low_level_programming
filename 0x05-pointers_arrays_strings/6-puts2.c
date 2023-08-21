#include "main.h"
/**
 * puts2 - prints every other character of a string,
 * starting with the first character, followed by a new line.
 * @str : string to print
 *
 * Return: string
 */
void puts2(char *str)
{
	int j;

	for (j = 0; str[j] != '\0'; j += 2)
	{
		_putchar(str[j]);
	}
	_putchar('\n');
}
