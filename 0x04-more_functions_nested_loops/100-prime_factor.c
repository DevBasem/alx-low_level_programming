#include <stdio.h>
/**
 * findLargestPrimeFactor - finds the largest prime factor of a number.
 * @n : is the number to check.
 *
 * Return: the largest prime factor.
 */
long long findLargestPrimeFactor(long long n)
{
	long long largestPrime = -1;

	while (n % 2 == 0)
	{
		largestPrime = 2;
		n /= 2;
	}
	for (long long i = 3; i * i <= n; i += 2)
	{
		while (n % i == 0)
		{
			largestPrime = i;
			n /= i;
		}
	}
	if (n > 2)
	{
		largestPrime = n;
	}
	return (largestPrime);
}
/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	long long number = 612852475143;
	long long largestPrime = findLargestPrimeFactor(number);

	printf("%lld\n", largestPrime);
	return (0);
}
