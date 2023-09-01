#include "main.h"
/**
 * *_strchr - locates a character in a string.
 * @s: string.
 * @c: character to be located.
 *
 * Return: modified string.
 */
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		s++;
		if (*s == c)
			return (s);
	}
	return (0);

}
