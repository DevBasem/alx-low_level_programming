#include "main.h"
/**
 * swap_int - swaps the values of two integers.
 * @a : first number to swap
 * @b : second number to swap
 *
 * Return: swaped numbers
 */
void swap_int(int *a, int *b)
{
int tmp1 = *a;
int tmp2 = *b;
*a = tmp2;
*b = tmp1;
}
