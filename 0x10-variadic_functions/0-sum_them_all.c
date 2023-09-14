#include "variadic_functions.h"

/**
 * sum_them_all - returns the sum of all its parameters.
 * @n: number of args
 *
 * Return: Nothing.
 */
int sum_them_all(const unsigned int n, ...)
{
	int total = 0;
	va_list args;
	unsigned int i;
	int num;

	if (n == 0)
		return (0);
	va_start(args, n);
	for (i = 0; i < n; i++)
	{
		num = va_arg(args, int);
		total += num;
	}
	va_end(args);
	return (total);
}
