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
	int i , j;
	char *ptr;
	int length = 0;

	for (i = 0; i < ac; i++)
	{
		length += strlen(av[i]) + 1; 
	}	
	ptr = (char *)malloc(length * sizeof(char));
	if (ptr == NULL)
	{
		return (NULL);
	}
	j = 0;
	for (i = 0; i < ac; i++)
	{
		strcpy(ptr + j, av[i]);
		j += strlen(av[i]);
		ptr[j++] = '\n';
	}
	ptr[j - 1] = '\n';
	return (ptr);
}
