#include "main.h"
/**
 * print_to_98 - prints all natural numbers from n to 98
 * @n: starting number
 *
 * Return: all numbers printed to 98
 */
void print_to_98(int n)
{
int c;
if (n > 98)
for (c = n; c > 98; c--)
printf("%d, ", c);
else
for (c = n; c < 98; c++)
printf("%d, ", c);
printf("98\n");
}
