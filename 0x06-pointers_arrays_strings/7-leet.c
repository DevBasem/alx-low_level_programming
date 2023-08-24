#include "main.h"
/**
 * *leet - encodes a string into 1337.
 * @input: string to encode.
 *
 * Return: encoded string
 */
char *leet(char *input)
{
	char *original = input;
	char *leetChars = "AEOTL";
	char *leetReplacements = "43071";

	while (*input != '\0')
	{
		bool replaced = false;
		int i;

		for (i = 0; leetChars[i] != '\0'; i++)
		{
			if (*input == leetChars[i] || *input == leetChars[i] + 32)
			{
				*input = leetReplacements[i];
				replaced = true;
				break;
			}
		}

		if (!replaced)
		{
			input++;
		}
	}

	return (original);
}
