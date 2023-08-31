#include "main.h"
int master_is_prime_number(int n, int d);
/**
 * is_prime_number - dummy function.
 * @n: number.
 *
 * Return: result.
 */
int is_prime_number(int n)
{
	return (master_is_prime_number(n, n - 1));
}

/**
 * master_is_prime_number - returns 1 if the input integer is a prime number,
 * otherwise return 0.
 * @n: number.
 * @d: n - 1.
 *
 * Return: result.
 */
int master_is_prime_number(int n, int d)
{
	if (n <= 1)
		return (0);
	if (d <= 1)
	{
		return (1);
	}
	if (n % d == 0)
	{
		return (0);
	}
	return (master_is_prime_number(n, d - 1));
}
