#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *allocate_buffer(char *output_file);
void close_file_descriptor(int fd);

/**
 * allocate_buffer - Allocates 1024 bytes for a buffer.
 * @output_file: The name of the file buffer is storing chars for.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *allocate_buffer(char *output_file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", output_file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file_descriptor - Closes file descriptors.
 * @fd: The file descriptor to be closed.
 */
void close_file_descriptor(int fd)
{
	int close_result;

	close_result = close(fd);

	if (close_result == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect - exit code 97.
 * If source_file does not exist or cannot be read - exit code 98.
 * If destination_file cannot be created or written to - exit code 99.
 * If destination_file or source_file cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int source_fd, destination_fd, read_result, write_result;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp source_file destination_file\n");
		exit(97);
	}

	buffer = allocate_buffer(argv[2]);
	source_fd = open(argv[1], O_RDONLY);
	read_result = read(source_fd, buffer, 1024);
	destination_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (source_fd == -1 || read_result == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		write_result = write(destination_fd, buffer, read_result);
		if (destination_fd == -1 || write_result == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		read_result = read(source_fd, buffer, 1024);
		destination_fd = open(argv[2], O_WRONLY | O_APPEND);

	} while (read_result > 0);

	free(buffer);
	close_file_descriptor(source_fd);
	close_file_descriptor(destination_fd);

	return (0);
}
