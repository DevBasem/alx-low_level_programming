#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to standard output.
 * @filename: The name of the file to read.
 * @letters: The number of letters to read and print.
 *
 * Return: The actual number of letters read and printed, or 0 on failure.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t n, file_descriptor;
	char *buffer;
	ssize_t printed_chars = 0;

	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
	{
		free(buffer);
		return (0);
	}

	while ((n = read(file_descriptor, buffer, letters)) > 0)
	{
		ssize_t written = write(STDOUT_FILENO, buffer, n);
		if (written == -1)
		{
			free(buffer);
			close(file_descriptor);
			return (0);
		}
		printed_chars += written;
	}

	free(buffer);
	close(file_descriptor);
	return (printed_chars);
}
