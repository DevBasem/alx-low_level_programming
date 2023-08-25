#include "main.h"
/**
 * print_buffer - function that prints a buffer.
 * @b: buffer
 * @size: bytes of the buffer
 *
 * Return: printed buffer
 */
void print_buffer(char *b, int size)
{
	int i, j;

	for (i = 0; i < size || (size <= 0 && i == 0); i += 10)
	{
		printf("%08x: ", i);

		for (j = 0; j < 10; j++)
		{
			if (i + j < size)
			{
				printf("%02x ", (unsigned char)b[i + j]);
			}
			else
			{
				printf("   ");
			}
		}

		for (j = 0; j < 10; j++)
		{
			if (i + j < size)
			{
				if (b[i + j] >= 32 && b[i + j] <= 126)
				{
					printf("%c", b[i + j]);
				}
				else
				{
					printf(".");
				}
			}
		}

		printf("\n");
	}
}
