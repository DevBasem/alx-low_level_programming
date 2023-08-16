#include "main.h"
/**
 * print_times_table - prints the n times table, starting with 0.
 *
 * @n: table size
 *
 * Return: all numbers of table
 */
void print_times_table(int n)
{
int x, i, j;
if (n <= 15 && n >= 0)
{
for (i = 0; i <= n; ++i)
{
_putchar(48);
for (j = 1; j <= n; ++j)
{
_putchar (',');
_putchar (' ');
x = i * j;
if (x <= 9)
_putchar (' ');
if (x <= 99)
_putchar (' ');
if (x >= 100)
{
_putchar((x / 100) + 48);
_putchar((x / 10) % 10 + 48);
}
else if (x <= 99 && x >= 10)
_putchar((x / 10) + 48);
_putchar((x % 10) + 48);
}
_putchar ('\n');
}
}
}
