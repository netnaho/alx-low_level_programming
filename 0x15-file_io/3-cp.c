#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "main.h"

#define READ_ERR "Error: Can't read from file %s\n"
#define WRITE_ERR "Error: Can't write to %s\n"

/**
 * main - the main function to run
 * @argc: number of arguments
 * @argv: arguments
 * Return: return 0.
 */
int main(int argc, char **argv)
{
	int from, upto, right_close, k, h;
	char buffer[1024];

	if (argc != 3)
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"), exit(97);
	upto = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (upto == -1)
		dprintf(STDERR_FILENO, WRITE_ERR, argv[2]), exit(99);
	from = open(argv[1], O_RDONLY);
	if (from == -1)
		dprintf(STDERR_FILENO, READ_ERR, argv[1]), exit(98);
	while (1)
	{
		h = read(from, buffer, 1024);
		if (h == -1)
			dprintf(STDERR_FILENO, READ_ERR, argv[1]), exit(98);
		if (h > 0)
		{
			k = write(upto, buffer, h);
			if (k == -1)
				dprintf(STDERR_FILENO, WRITE_ERR, argv[2]), exit(99);
		} else
			break;
	}
	right_close = close(from);
	if (right_close == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", from), exit(100);
	right_close = close(to);
	if (right_close == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", to), exit(100);
	return (0);
}
