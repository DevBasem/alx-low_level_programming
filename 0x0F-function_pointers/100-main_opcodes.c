#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prints opcodes from the main function in hexadecimal format
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 *
 * Return:
 *  0 on success (opcodes printed in hexadecimal)
 *  1 if the argument count is incorrect (error message displayed)
 *  2 if the number of bytes is negative (error message displayed)
 */
int main(int argc, char *argv[])
{
	int i;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	int bytes = atoi(argv[1]);

	if (bytes < 0)
	{
		printf("Error\n");
		return (2);
	}

	char *main_ptr = (char *)main;

	for (i = 0; i < bytes; i++)
	{
		if (i == bytes - 1)
		{
			printf("%02hhx\n", main_ptr[i]);
		}
		else
		{
			printf("%02hhx ", main_ptr[i]);
		}
	}

	return (0);
}
