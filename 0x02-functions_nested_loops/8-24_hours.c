#include "main.h"
/**
 * jack_bauer - prints every minute of the day of Jack Bauer,
 * starting from 00:00 to 23:59
 *
 * Return: every minute
 */
void jack_bauer(void)
{
int x;
int y;
int z;
int j;
int k = 0;
for (x = 48; x <= 57; x++)
{
for (y = 48; y <= 57; y++)
{
for (z = 48; z <= 57; z++)
{
for (j = 48; j <= 57; j++)
{
k++;
_putchar (x);
_putchar (y);
_putchar (':');
_putchar (z);
_putchar (j);
_putchar ('\n');
if (z == 53 && j == 57)
{
z = 57;
j = 57;
}
if (k == 1440)
{
x = 57;
y = 57;
z = 57;
j = 57;
}
}
}
}
}
}
