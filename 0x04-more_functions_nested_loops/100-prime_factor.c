#include <stdio.h>
/**
 * largestPrimeFactor - finds the largest prime factor of a number.
 * @n : is the number to check.
 *
 * Return: the largest prime factor.
 */
long largestPrimeFactor(long n)
{
	long factor = 2;

	while (n > 1)
	{
		if (n % factor == 0)
		{
			n /= factor;
		}
		else
		{
			factor++;
		}
	}
	return (factor);
}
/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	long number = 612852475143;
	long result = largestPrimeFactor(number);

	printf("%ld\n", result);

	return (0);
}
