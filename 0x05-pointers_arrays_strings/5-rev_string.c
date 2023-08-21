#include "main.h"
/**
 * rev_string - reverses a string.
 * @s : string to print
 *
 * Return: rev string
 */
void rev_string(char *s)
{
	int i, j;
	char temp;

	for (j = 0, i = strlen(s) - 1; j < i; i--, j++)
	{
		temp = s[j];
		s[j] = s[i];
		s[i] = temp;
	}
}
