#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(void);
void close_file(int fd);

/**
 * create_buffer - Allocates 1024 bytes for a buffer.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *create_buffer(void)
{
	char *buffer;

	buffer = malloc(1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't allocate memory for the buffer\n");
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - Closes file descriptors.
 * @fd: The file descriptor to be closed.
 */
void close_file(int fd)
{
	int result;

	result = close(fd);

	if (result == -1)
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
 * If source_file or destination_file cannot be closed - exit code 100.
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

	buffer = create_buffer();
	source_fd = open(argv[1], O_RDONLY);
	if (source_fd == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
		free(buffer);
		exit(98);
	}

	destination_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (destination_fd == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't create or write to %s\n", argv[2]);
		free(buffer);
		exit(99);
	}

	do

	{
		read_result = read(source_fd, buffer, 1024);

		if (read_result == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			close_file(source_fd);
			close_file(destination_fd);
			exit(98);
		}

		write_result = write(destination_fd, buffer, read_result);

		if (write_result == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			close_file(source_fd);
			close_file(destination_fd);
			exit(99);
		}

	} while (read_result > 0);

	free(buffer);
	close_file(source_fd);
	close_file(destination_fd);

	return (0);
}
