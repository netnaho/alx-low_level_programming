#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: pointer to a string of 0 and 1 chars
 *
 * Return: the converted number, or 0 if there is an invalid char or b is NULL
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int res = 0;

	if (b == NULL)
		return 0;

	for (int i = 0; b[i] != '\0'; i++)
	{
		if (b[i] == '0')
			res <<= 1;
		else if (b[i] == '1')
			res = (res << 1) | 1;
		else
			return 0;
	}

	return res;
}
