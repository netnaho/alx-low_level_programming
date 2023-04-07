#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: pointer to a string of 0 and 1 chars
 *
 * Return: the converted number, or 0 if there is one or more chars in the
 *         string b that is not 0 or 1, or b is NULL
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0, base = 1;

	if (b == NULL)
		return 0;

	int len = 0;
	while (b[len] != '\0')
		len++;

	for (int i = len - 1; i >= 0; i--)
	{
		if (b[i] == '0' || b[i] == '1')
		{
			result += (b[i] - '0') * base;
			base *= 2;
		}
		else
		{
			return 0; /* invalid character */
		}
	}

	return result;
}
