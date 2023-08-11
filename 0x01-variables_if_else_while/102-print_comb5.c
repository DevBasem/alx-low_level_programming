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
for (i = 0; i <= 98; i++)
{
for (j = i + 1; j <= 99; j++)
{
putchar((i / 10) + '0');
putchar((i % 10) + '0');
putchar(' ');
putchar((j / 10) + '0');
putchar((j % 10) + '0');
if (i < 98 || j < 99)
{
putchar(',');
putchar(' ');
}
}
}
putchar('\n');
return (0);
}
