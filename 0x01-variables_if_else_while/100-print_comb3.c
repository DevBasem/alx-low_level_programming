#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 *
 * this program prints combinations of single digit numbers
 */
int main(void)
{
int i = 0;
int j;
for (i = 0; i <= 8; i++)
{
for (j = i + 1; j <= 9; j++)
{
putchar(i + '0');
putchar(j + '0');
if (i < 8 || j < 9)
{
putchar(',');
putchar(' ');
}
}
}
putchar('\n');
return (0);
}
