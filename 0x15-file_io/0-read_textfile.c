#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "main.h"

/**
 * read_textfile - reads and prints from a file
 * @filename: path to file
 * @letters: chars to read
 * Return: chars read
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char *nahh;
	ssize_t bytes, r;

	if (!filename)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (0);
	}

	nahh = malloc(sizeof(char) * letters);
	if (!nahh)
	{
		close(fd);
		return (0);
	}

	bytes = read(fd, nahh, letters);

	if (bytes == -1)
	{
		close(fd);
		free(nahh);
		return (0);
	}

	r = write(STDOUT_FILENO, nahh, bytes);

	if (r == -1)
	{
		close(fd);
		free(nahh);
		return (0);
	}
	close(fd);
	return (bytes);
}
