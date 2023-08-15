#include "main.h"
/**
 * times_table - prints the 9 times table, starting with 0.
 *
 * Return: all the table values
 */
void times_table(void)
{
int i;
int j;
int x;
for (i = 0; i <= 9; i++)
{
_putchar (48);
for (j = 1; j <= 9; j++)
{
_putchar (',');
_putchar (' ');
x = i * j;
if (x <= 9)
_putchar (' ');
else
_putchar ((x / 10) + 48);
_putchar ((x % 10) + 48);
}
_putchar ('\n');
}
}
