#include "main.h"

/**
 * flip_bits - Counts the number of bits needed to be
 * flipped to get from one number to another.
 * @n: The number.
 * @m: To flip n to.
 * Return: The necessary number of bits to flip to get from n to m.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int used_diff, used_bits = 0;

	used_diff = n ^ m;

	while (used_diff > 0)
	{
		used_bits += (used_diff & 1);
		used_diff >>= 1;
	}

	return (used_bits);
}
