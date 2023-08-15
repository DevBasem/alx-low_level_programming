#include "main.h"
/**
 * print_sign - checks number for positive or negative
 * @n: The number to check
 *
 * Return: 1 if positive or 0 if 0 or -1 if negative
 */
int print_sign(int n)
{
if (n > 0)
{
putchar ('+');
return (1);
}
else if (n == 0)
{
putchar ('0');
return (0);
}
else
{
putchar ('-');
return (-1);
}
putchar ('\n');
}
