#include "main.h"
/**
 * print_last_digit - prints the last digit of a number.
 * @n: The number to check
 *
 * Return: the value of the last digit
 */
int print_last_digit(int n)
{
int lNum;
if (n < 0)
{
lNum = -1 * (n % 10);
}
else
{
lNum = n % 10;
}
_putchar (lNum + '0');
return (lNum);
}
