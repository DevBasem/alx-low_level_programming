#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *allocate_buffer(char *output_file);
void close_file_descriptor(int fd);

/**
 * allocate_buffer - Allocates a buffer of 1024 bytes for file operations.
 * @output_file: The name of the output file.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *allocate_buffer(char *output_file)
{
	char *buffer = malloc(1024);

	if (buffer == NULL)
	{
		fprintf(stderr, "Error: Unable to allocate buffer for %s\n", output_file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file_descriptor - Closes a file descriptor.
 * @fd: The file descriptor to be closed.
 */
void close_file_descriptor(int fd)
{
	int result = close(fd);

	if (result == -1)
	{
		fprintf(stderr, "Error: Unable to close file descriptor %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies the contents of one file to another file.
 * @argc: The number of command-line arguments.
 * @argv: An array of pointers to the command-line arguments.
 *
 * Return: 0 on success, non-zero exit codes on failure.
 */
int main(int argc, char *argv[])
{
	int source_fd, dest_fd, bytes_read, bytes_written;
	char *buffer;

	if (argc != 3)
	{
		fprintf(stderr, "Usage: cp source_file destination_file\n");
		exit(97);
	}

	buffer = allocate_buffer(argv[2]);

	source_fd = open(argv[1], O_RDONLY);
	dest_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do
	{
		if (source_fd == -1 || (bytes_read = read(source_fd, buffer, 1024)) == -1)
		{
			fprintf(stderr, "Error: Unable to read from %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		dest_fd = open(argv[2], O_WRONLY | O_APPEND);
		if (dest_fd == -1 || (bytes_written = write(dest_fd, buffer, bytes_read)) == -1)
		{
			fprintf(stderr, "Error: Unable to write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}
	} while (bytes_read > 0);

	free(buffer);
	close_file_descriptor(source_fd);
	close_file_descriptor(dest_fd);

	return (0);
}
