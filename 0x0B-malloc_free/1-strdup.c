#include "main.h"
/**
 * *_strdup -  that returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: string to be copied.
 *
 * Return:copied array.
 */
char *_strdup(char *str)
{
	char *ptr;
	char *ret;
	int size;

	size = strlen(str);
	ptr = malloc((size + 1) * sizeof(*str));
	if (str == NULL)
	{
		return (NULL);
	}
	ret = ptr;
	while (*str != '\0')
	{
		*ptr++ = *str++;
	}
	return (ret);
}
