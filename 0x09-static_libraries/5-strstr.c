#include "main.h"
/**
 * *_strstr - locates a substring.
 * @haystack: string.
 * @needle: accepted characters.
 *
 * Return: located substring, or NULL.
 */
char *_strstr(char *haystack, char *needle)
{
	int i;
	int j;

	while (*haystack)
	{
		for (i = 0, j = 0; needle[j] != '\0'; i++, j++)
		{
			if (haystack[i] != needle[j])
			{
				break;
			}
		}
		if (needle[j] == '\0')
		{
			return (haystack);
		}
		haystack++;
	}
	return (NULL);
}
