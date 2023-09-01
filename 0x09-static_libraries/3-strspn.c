#include "main.h"
/**
 * _strspn - gets the length of a prefix substring.
 * @s: string.
 * @accept: accepted characters.
 *
 * Return: number of accepted characters.
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int k = 0;
	int i;

	while (*s != '\0')
	{
		for (i = 0; accept[i] != '\0'; i++)
		{
			if (*s == accept[i])
			{
				k++;
				break;
			}
			else if (accept[i + 1] == '\0')
				return (k);
		}
		s++;
	}
	return (k);
}
