#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 *
 * this program prints all the numbers of base 16 in lowercase
 */
int main(void)
{
int x = 48;
int y = 97;
while (x <= 57)
{
putchar(x);
x++;
}
while (y <= 102)
{
putchar(y);
y++;
}
putchar('\n');
return (0);
}
