#include "main.h"

/**
 * get_bit - returns the value of the bit at a given index.
 *
 * @n: the unsigned long int to check.
 * @index: the index of the bit to get (0 is the least significant bit).
 *
 * Return: the value of the bit at the given index (0 or 1), or -1 if an error occurred.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	unsigned long int mask = 1UL << index;
	unsigned long int masked_n = n & mask;

	return (masked_n != 0) ? 1 : 0;
}
