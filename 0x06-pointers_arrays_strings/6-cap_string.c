#include "main.h"
/**
 * is_separator - checks for sperator.
 * @c: element to check
 * Return: true or false
 */
bool is_separator(char c)
{
	char separators[] = " \t\n,;.!?\"(){}";
	int i;

	for (i = 0; separators[i] != '\0'; i++)
	{
		if (c == separators[i])
		{
			return (true);
		}
	}
	return (false);
}
/**
 * *cap_string - changes words to uppercase.
 * @str: string to convert.
 * Return: uppercase string
 */
char *cap_string(char *str)
{
	bool new_word = true;
	char *saveStr = str;

	while (*str != '\0')
	{
		if (is_separator(*str))
		{
			new_word = true;
		}
		else
		{
			if (new_word)
			{
				*str = toupper(*str);
				new_word = false;
			}
			else
			{
				*str = tolower(*str);
			}
		}
		str++;
	}

	return (saveStr);
}
