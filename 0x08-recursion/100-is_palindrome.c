#include "main.h"
int master_is_palindrome(char *s, int st, int end);
/**
 * is_palindrome - dummy function.
 * @s: string.
 *
 * Return: result.
 */
int is_palindrome(char *s)
{
	int len = strlen(s);

	if (len <= 1)
	{
		return (1);
	}
	return (master_is_palindrome(s, 0, len - 1));
}
/**
 * master_is_palindrome - returns 1 if a string is a palindrome and 0 if not.
 * @s: string.
 * @st: start.
 * @end: end.
 *
 * Return: result.
 */
int master_is_palindrome(char *s, int st, int end)
{
	if (st >= end)
	{
		return (1);
	}

	if (s[st] != s[end])
	{
		return (0);
	}

	return (master_is_palindrome(s, st + 1, end - 1));
}
