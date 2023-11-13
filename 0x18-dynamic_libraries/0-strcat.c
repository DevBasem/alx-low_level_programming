#include "main.h"
/**
 * *_strcat - concatenates two strings.
 * @dest : string 2
 * @src : string 1
 *
 * Return: the two string combined
 */
char *_strcat(char *dest, char *src)
{
	char *oldDest = dest;

	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	return (oldDest);
}
