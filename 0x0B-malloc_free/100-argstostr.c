#include "main.h"
/**
 * argstostr - concatenates all the arguments of your program.
 * @ac: arguments count.
 * @av: arguments vector.
 *
 * Return: nothing.
 */
char *argstostr(int ac, char **av)
{
	int total_length = 0;
	char *result;
	int index = 0;
	int i;

	if (ac == 0 || av == NULL)
	{
		return NULL;
	}

	for (i = 0; i < ac; i++)
	{
		total_length += strlen(av[i]) + 1;
	}

	result = (char *)malloc(total_length + 1);
	if (result == NULL)
	{
		return NULL;
	}

	for (i = 0; i < ac; i++)
	{
		strcpy(result + index, av[i]);
		index += strlen(av[i]);
		result[index++] = '\n';
	}
	result[total_length] = '\0';

	return result;
}
