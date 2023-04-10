#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "main.h"

/**
 * create_file - the file to be appended on
 * @filename: the file path
 * @text_content: the content
 * Return: the read charachters
 */

int create_file(const char *filename, char *text_content)
{
	int dl;
	ssize_t k;
	int size;
	char *mem;

	if (!filename)
	{
		return (-1);
	}
	dl = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0600);
	if (dl == -1)
		return (-1);
	if (!text_content)
	{
		close(dl);
		return (1);
	}
	size = _strlen(text_content);
	mem = malloc(sizeof(char) * size);
	if (!mem)
	{
		close(dl);
		return (-1);
	}
	k = write(dl, text_content, size);
	if (k == -1)
	{
		close(dl);
		free(mem);
		return (-1);
	}
	close(dl);
	free(mem);
	return (1);
}

/**
 * _strlen - length
 *
 * @s: is charachter pointer
 *
 * Return: return 0.
 */

int _strlen(const char *s)
{
	int i = 0;

	while (*(s + i) != '\0')
	{
		i++;
	}

	return (i);
}
