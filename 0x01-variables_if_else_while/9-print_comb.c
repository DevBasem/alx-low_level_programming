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
int x = 48;
while (x <= 57)
{
putchar (x);
putchar (44);
putchar (' ');
x++;
}
putchar('\n');
return (0);
}
