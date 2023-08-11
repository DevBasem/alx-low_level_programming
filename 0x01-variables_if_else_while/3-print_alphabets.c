#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 *
 * this program prints alphabet in lowercase
 * and uppercase
 */
int main(void)
{
int x = 97;
int y = 65;
while (x <= 122)
{
putchar(x);
x++;
}
while (y <= 90)
{
putchar(y);
y++;
}
putchar('\n');
return (0);
}
