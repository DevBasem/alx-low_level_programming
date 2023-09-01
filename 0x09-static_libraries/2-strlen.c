#include "main.h"
/**
 * _strlen - returns the length of a string.
 * @s : string to calculate its length
 *
 * Return: length
 */
int _strlen(char *s)
{
	int length = 0;

	while (s[length] != '\0')
	{
		length++;
	}
	return (length);
}
