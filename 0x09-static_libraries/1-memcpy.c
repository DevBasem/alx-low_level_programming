#include "main.h"
/**
 * *_memcpy - copies memory area..
 * @dest: memory area of dest.
 * @src: memory area of src.
 * @n: the first n bytes of the memory area.
 *
 * Return: modified memorry of dest.
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	char *oldDest = dest;
	int i = 0;

	while (n > 0)
	{
		dest[i] = src[i];
		i++;
		n--;
	}
	return (oldDest);
}
