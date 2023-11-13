#include "main.h"
/**
 * *_strncpy - copies a string..
 * @dest : string 2
 * @src : string 1
 * @n : number of bytes from src
 *
 * Return: the two string combined
 */
char *_strncpy(char *dest, char *src, int n)
{
	char *oldDest = dest;

	while (*src != '\0' && n > 0)
	{
		*dest = *src;
		src++;
		dest++;
		n--;
	}
	while (n > 0)
	{
		*dest = '\0';
		dest++;
		n--;
	}
	return (oldDest);
}
