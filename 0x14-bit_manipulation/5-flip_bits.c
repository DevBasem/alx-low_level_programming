#include "main.h"

/**
 * flip_bits - Counts the number of bits to flip to get from n to m.
 * @n: The first unsigned long integer.
 * @m: The second unsigned long integer.
 *
 * Return: The number of bits to flip.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor_output = n ^ m;
	unsigned int count = 0;

	while (xor_output > 0)
	{
		if (xor_output & 1)
			count++;
		xor_output >>= 1;
	}

	return (count);
}
