#include "main.h"
/**
 * *rot13 - encodes a string using rot13.
 * @s: string to encode.
 * Return: encoded string.
 */
char *rot13(char *s)
{
	char *p = s;

	while (*p)
	{
		char c = *p;

		int shift = 0;
		if ((c >= 'a' && c <= 'z'))
		{
			shift = c <= 'm' ? 13 : -13;
		}
		else if ((c >= 'A' && c <= 'Z'))
		{
			shift = c <= 'M' ? 13 : -13;
		}

		*p += shift;
		p++;
	}

	return (s);
}
