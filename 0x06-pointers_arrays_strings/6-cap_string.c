#include "main.h"

/**
 * cap_string - Capitalizes all words of a string.
 * @a: The string to be capitalized.
 *
 * Return: capitalized all words
 */
char *cap_string(char *a)
{
	int index = 0;

	while (a[index])
	{
		while (!(a[index] >= 'a' && a[index] <= 'z'))
			index++;
		if (a[index - 1] == ' ' ||
				a[index - 1] == '\t' ||
				a[index - 1] == '\n' ||
				a[index - 1] == ',' ||
				a[index - 1] == ';' ||
				a[index - 1] == '.' ||
				a[index - 1] == '!' ||
				a[index - 1] == '?' ||
				a[index - 1] == '"' ||
				a[index - 1] == '(' ||
				a[index - 1] == ')' ||
				a[index - 1] == '{' ||
				a[index - 1] == '}' ||
				index == 0)
			a[index] -= 32;
		index++;
	}
	return (a);
}
