#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 *
 * this program prints the alphabet in lowercase
 * in reverse
 */
int main(void)
{
int x = 122;
while (x >= 97)
{
putchar(x);
x--;
}
putchar('\n');
return (0);
}
