#include "main.h"
/**
 * *_memset - fills memory with a constant byte.
 * @s: area pointed to by s.
 * @b: constant byte b.
 * @n: the first n bytes of the memory area.
 *
 * Return: modified memorry of s.
 */
char *_memset(char *s, char b, unsigned int n)
{
	char *oldS = s;
	int i = 0;

	while (n > 0)
	{
		s[i] = b;
		i++;
		n--;
	}
	return (oldS);
}
