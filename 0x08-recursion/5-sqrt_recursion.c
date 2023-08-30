#include "main.h"
int master_sqrt_recursion(int n, int x);
/**
 * _sqrt_recursion - dummy function.
 * @n: number.
 *
 * Return: result.
 */
int _sqrt_recursion(int n)
{
	return (master_sqrt_recursion(n, 0));
}

/**
 * master_sqrt_recursion - returns the natural square root of a number.
 * @n: number.
 * @x: guess.
 *
 * Return: result.
 */
int master_sqrt_recursion(int n, int x)
{
	if (n < 0)
		return (-1);
	if (x * x > n)
		return (-1);
	if (x * x == n)
		return (x);
	return (master_sqrt_recursion(n, x + 1));
}
