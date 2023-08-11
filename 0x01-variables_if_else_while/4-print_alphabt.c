#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 *
 * this program prints the alphabet in lowercase
 */
int main(void)
{
int x = 97;
while (x <= 122)
{
if (x == 101 || x == 113)
{
putchar(0);
x++;
}
else
{
putchar(x);
x++;
}
}
putchar('\n');
return (0);
}
