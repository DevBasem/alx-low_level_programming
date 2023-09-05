#include "main.h"
#include <stdlib.h>

/**
 * count_words - Count the number of words in a string.
 * @s: String.
 *
 * Return: Number of words.
 */
int count_words(char *s)
{
	int in_word = 0;
	int word_count = 0;
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == ' ')
			in_word = 0;
		else if (in_word == 0)
		{
			in_word = 1;
			word_count++;
		}
	}
	return (word_count);
}

/**
 * strtow - Splits a string into words.
 * @str: String to split.
 *
 * Return: Pointer to an array of strings (Success)
 * or NULL (Error)
 */
char **strtow(char *str)
{
	char **word_matrix, *tmp;
	int i, matrix_index = 0, str_len = 0,
	word_count, char_index = 0, word_start, word_end;

	while (*(str + str_len))
		str_len++;
	word_count = count_words(str);
	if (word_count == 0)
		return (NULL);
	word_matrix = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (word_matrix == NULL)
		return (NULL);
	for (i = 0; i <= str_len; i++)
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			if (char_index)
			{
				word_end = i;
				tmp = (char *)malloc(sizeof(char) * (char_index + 1));
				if (tmp == NULL)
					return (NULL);
				word_start = i - char_index;
				while (word_start < word_end)
					*tmp++ = str[word_start++];
				*tmp = '\0';
				word_matrix[matrix_index] = tmp - char_index;
				matrix_index++;
				char_index = 0;
			}
		}
		else if (char_index++ == 0)
			word_start = i;
	}
	word_matrix[matrix_index] = NULL;
	return (word_matrix);
}
