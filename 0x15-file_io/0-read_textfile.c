#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "main.h"

/**
 * read_textfile - prints and reads from a file
 * @filename: the file to path
 * @letters: the charachter to be read
 * Return: chars read
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int dl;
	char *nahh;
	ssize_t bytes, r;

	if (!filename)
		return (0);
	dl = open(filename, O_RDONLY);
	if (dl == -1)
	{
		close(dl);
		return (0);
	}

	nahh = malloc(sizeof(char) * letters);
	if (!nahh)
	{
		close(dl);
		return (0);
	}

	bytes = read(dl, nahh, letters);

	if (bytes == -1)
	{
		close(dl);
		free(nahh);
		return (0);
	}

	r = write(STDOUT_FILENO, nahh, bytes);

	if (r == -1)
	{
		close(dl);
		free(nahh);
		return (0);
	}
	close(dl);
	return (bytes);
}
