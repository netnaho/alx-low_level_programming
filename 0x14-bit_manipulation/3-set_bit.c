#include "main.h"

/**
 * set_bit - function to run
 * @n: number
 * @index: index binary number
 * Return: 1 if true, or -1 if false
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int nummber = 1;

	if (index > (sizeof(unsigned long int) * 8))
		return (-1);

	number <<= index;/*shift the value in set left by 1 bit.*/
	/*num <<= index is the same as num = num << index*/

	*n = *n | number;/*bitwise OR operator*/
	return (1);
}
