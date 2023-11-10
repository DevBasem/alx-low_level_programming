#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CODEX "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk"

/**
 * main - Generates and prints passwords for the crackme5 executable.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: Always 0.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	char password[7];
	int len = strlen(argv[1]), i, tmp = 0;

	password[0] = CODEX[(len ^ 59) & 63];

	for (i = 0; i < len; i++)
		tmp += argv[1][i];
	password[1] = CODEX[(tmp ^ 79) & 63];

	tmp = 1;
	for (i = 0; i < len; i++)
		tmp *= argv[1][i];
	password[2] = CODEX[(tmp ^ 85) & 63];

	tmp = 0;
	for (i = 0; i < len; i++)
		tmp = (argv[1][i] > tmp) ? argv[1][i] : tmp;
	srand(tmp ^ 14);
	password[3] = CODEX[rand() & 63];

	tmp = 0;
	for (i = 0; i < len; i++)
		tmp += argv[1][i] * argv[1][i];
	password[4] = CODEX[(tmp ^ 239) & 63];

	for (i = 0; i < argv[1][0]; i++)
		rand();
	password[5] = CODEX[(rand() ^ 229) & 63];

	password[6] = '\0';
	printf("%s", password);
	return (0);
}
