#include "main.h"
/**
 * _strspn - gets the length of a prefix substring.
 * @s: string.
 * @accept: accepted characters.
 *
 * Return: number of accepted characters.
 */
char *_strpbrk(char *s, char *accept)
{
	int i;

	while (*s != '\0')
	{
		for (i = 0; accept[i] != '\0'; i++)
		{
			if (*s == accept[i])
			{
				return ((char *)s);
			}
		}
		s++;
	}
	return (NULL);
}
