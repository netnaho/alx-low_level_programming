#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "main.h"

#define READ_ERR "Error: Can't read from file %s\n"
#define WRITE_ERR "Error: Can't write to %s\n"

/**
 * main - the main function.
 * @argc: number of argument
 * @argv: arguments
 * Return: return 0.
 */
int main(int argc, char **argv)
{
	int from, to, close_on, k, l;
	char buffer[1024];

	if (argc != 3)
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"), exit(97);
	to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (to == -1)
		dprintf(STDERR_FILENO, WRITE_ERR, argv[2]), exit(99);
	from = open(argv[1], O_RDONLY);
	if (from == -1)
		dprintf(STDERR_FILENO, READ_ERR, argv[1]), exit(98);
	while (1)
	{
		l = read(from, buffer, 1024);
		if (l == -1)
			dprintf(STDERR_FILENO, READ_ERR, argv[1]), exit(98);
		if (l > 0)
		{
			k = write(to, buffer, l);
			if (k == -1)
				dprintf(STDERR_FILENO, WRITE_ERR, argv[2]), exit(99);
		} else
			break;
	}
	close_on = close(from);
	if (close_on == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", from), exit(100);
	close_on = close(to);
	if (close_on == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", to), exit(100);
	return (0);
}
