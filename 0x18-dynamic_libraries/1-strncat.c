#include "main.h"
/**
 * *_strncat - concatenates two strings.
 * @dest : string 2
 * @src : string 1
 * @n : number of bytes from src
 *
 * Return: the two string combined
 */
char *_strncat(char *dest, char *src, int n)
{
	char *oldDest = dest;

	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0' && n > 0)
	{
		*dest = *src;
		src++;
		dest++;
		n--;
	}
	*dest = '\0';
	return (oldDest);
}
