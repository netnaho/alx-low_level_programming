#include "main.h"

/**
 * get_bit - Returns the value of the bit at a given index.
 *
 * @n: The unsigned long int to check.
 * @index: The index of the bit to get (0 is the least significant bit).
 *
 * Return: The value of the bit at the given index (0 or 1), or -1 if an error occurred.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= sizeof(n) * 8)
	{
		/* Error: index out of range */
		return -1;
	}

	unsigned long int mask = 1UL << index;
	unsigned long int masked_n = n & mask;

	return masked_n > 0 ? 1 : 0;
}
