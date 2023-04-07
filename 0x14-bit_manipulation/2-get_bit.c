#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index
 * @n: the number to check
 * @index: the index of the bit to get (0 is the least significant bit)
 *
 * Return: the value of the bit at the given index, or -1 if an error occurred
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= sizeof(n) * 8) {
		/* Error: index out of range */
		return -1;
	}

	unsigned long int mask = 1UL << index;
	return (n & mask) ? 1 : 0;
}
