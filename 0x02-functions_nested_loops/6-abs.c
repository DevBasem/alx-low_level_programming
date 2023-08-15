#include "main.h"
/**
 * _abs - computes the absolute value of an integer.
 * @n: The number to check
 *
 * Return: 1 if positive or 0 if 0 or -1 if negative
 */
int _abs(int n)
{
if (n < 0)
{
return (n * -1);
}
else
{
return (n);
}
}
