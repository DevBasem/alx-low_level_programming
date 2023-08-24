#include "main.h"
/**
 * *cap_string - changes words to uppercase.
 * @str: string to convert.
 *
 * Return: uppercase string
 */
char *cap_string(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] >= 97 && str[i] <= 122)
		{
		if (str[i - 1] == ' ' || str[i - 1] == '\t'
		|| str[i - 1] == '\n' || str[i - 1] == ','
		|| str[i - 1] == ';' || str[i - 1] == '.'
		|| str[i - 1] == '!' || str[i - 1] == '?'
		|| str[i - 1] == '"' || str[i - 1] == '('
		|| str[i - 1] == ')' || str[i - 1] == '{' || str[i - 1] == '}')
			{
			str[i] -= 32;
			}
		}
		i++;
	}
	return (str);
}
