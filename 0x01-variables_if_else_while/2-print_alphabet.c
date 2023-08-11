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
putchar(x);
x++;
}
putchar('\n');
return (0);
}
