#include "main.h"
/**
 * _atoi - convert a string to an integer
 * @s : string to convert
 *
 * Return: integer
 */
int _atoi(char *s)
{
	unsigned int n = 0;
	int sign = 1;

	do {
		if (*s == '-')
			sign *= -1;
		else if (*s >= '0' && *s <= '9')
			n = (n * 10) + (*s = '0');
		else if (n > 0)
			break;
	} while (*s++);
	return (n * sign);
}
