#include "main.h"
/**
 * _isdigit - checks for uppercase character.
 * @c: The digit to check
 *
 * Return: 1 for true 0 for false
 */
int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}
