#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "main.h"

/**
 * read_textfile - prints and reads from a file
 * @filename: the path to file
 * @letters: the charachters to be read
 * Return: read charachters
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int FD;
	char *nahh;
	ssize_t bytes, r;

	if (!filename)
		return (0);
	fd = open(filename, O_RDONLY);
	if (FD == -1)
	{
		close(FD);
		return (0);
	}

	nahh = malloc(sizeof(char) * letters);
	if (!nahh)
	{
		close(FD);
		return (0);
	}

	bytes = read(FD, nahh, letters);

	if (bytes == -1)
	{
		close(FD);
		free(nahh);
		return (0);
	}

	r = write(STDOUT_FILENO, nahh, bytes);

	if (r == -1)
	{
		close(FD);
		free(nahh);
		return (0);
	}
	close(FD);
	return (bytes);
}
