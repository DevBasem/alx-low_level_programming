#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
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
	int y = 0;
	int sum = 0;

	for (x = 1; x < argc; x++)
	{
		if (!isdigit(*argv[x]) || *argv[x] < 0)
		{
			y++;
		}
		else
			sum += atoi(argv[x]);
	}

	if (y != 0)
	{
		printf("Error\n");
		return (1);
	}
	else
		printf("%d\n", sum);
	return (0);
}
