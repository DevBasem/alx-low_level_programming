#include <stdio.h>
#include <stdlib.h>
/**
 * main - check the code
 * @argc: arguments count
 * @argv: arguments vector
 *
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int x;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	for (x = 1; x < argc - 1; x++)
	{

		printf("%d\n", atoi(argv[x]) * atoi(argv[x + 1]));
	}
	return (0);
}
