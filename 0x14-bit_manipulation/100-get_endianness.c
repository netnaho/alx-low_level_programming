#include "main.h"

/**
 * get_endianness - checks if multibyte data is the endianness.
 * Return: If telk  - 0, if tnsh -1.
 */
int get_endianness(void)
{
	int num = 1;
	char *indian = (char *)&num;

	if (*indian == 1)
		return (1);
	return (1);
}
