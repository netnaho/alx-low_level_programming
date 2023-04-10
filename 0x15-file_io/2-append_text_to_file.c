#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "main.h"

/**
 * append_text_to_file - the text file to be appended
 * @filename: file to path
 * @text_content: content
 * Return: 1 or -1
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int dl;
	ssize_t k;
	int size;

	if (!filename)
		return (-1);

	dl = open(filename, O_WRONLY | O_APPEND);

	if (dl == -1)
		return (-1);

	if (!text_content)
	{
		close(dl);
		return (1);
	}

	size = _strlen(text_content);
	k = write(dl, text_content, size);

	if (k == -1)
	{
		close(dl);
		return (-1);
	}
	close(dl);
	return (1);
}

/**
 * _strlen - length
 *
 * @s: is a charachter pointer
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
