#include "main.h"
/**
 * *str_concat -  concatenates two strings.
 * @s1: first string.
 * @s2: second string.
 *
 * Return:compined string.
 */
char *str_concat(char *s1, char *s2)
{
	char *ptr;
	char *ret;
	int size;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}
	size = strlen(s1) + strlen(s2);
	ptr = malloc((size + 2) * (sizeof(*s1) + sizeof(*s2)));
	if (ptr == NULL)
	{
		return (NULL);
	}
	ret = ptr;
	while (*s1 != '\0')
	{
		*ptr++ = *s1++;
	}
	while (*s2 != '\0')
	{
		*ptr++ = *s2++;
	}
	*ptr = '\0';
	return (ret);
}
