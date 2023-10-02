#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *allocate_copy_buffer(char *destination);
void close_file_descriptor(int fd);

/**
 * allocate_copy_buffer - Allocates a 1024-byte buffer for copying data.
 * @destination: The destination file to write data.
 *
 * Return: Pointer to the allocated buffer.
 */
char *allocate_copy_buffer(char *destination)
{
	char *copy_buffer;

	copy_buffer = malloc(sizeof(char) * 1024);

	if (copy_buffer == NULL)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't allocate buffer for %s\n", destination);
		exit(99);
	}

	return (copy_buffer);
}

/**
 * close_file_descriptor - Closes a file descriptor.
 * @fd: The file descriptor to close.
 */
void close_file_descriptor(int fd)
{
	int result;

	result = close(fd);

	if (result == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close file descriptor %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments.
 * @argv: An array of argument strings.
 *
 * Return: 0 on success.
 *
 * Description: Exits with specific error codes for various failure scenarios.
 */
int main(int argc, char *argv[])
{
	int source_fd, destination_fd, bytes_read, bytes_written;
	char *copy_buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp source_file destination_file\n");
		exit(97);
	}

	copy_buffer = allocate_copy_buffer(argv[2]);
	source_fd = open(argv[1], O_RDONLY);
	bytes_read = read(source_fd, copy_buffer, 1024);
	destination_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (source_fd == -1 || bytes_read == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't read from source file %s\n", argv[1]);
			free(copy_buffer);
			exit(98);
		}

		bytes_written = write(destination_fd, copy_buffer, bytes_read);
		if (destination_fd == -1 || bytes_written == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't write to destination file %s\n", argv[2]);
			free(copy_buffer);
			exit(99);
		}

		bytes_read = read(source_fd, copy_buffer, 1024);
		destination_fd = open(argv[2], O_WRONLY | O_APPEND);

	} while (bytes_read > 0);

	free(copy_buffer);
	close_file_descriptor(source_fd);
	close_file_descriptor(destination_fd);

	return (0);
}
