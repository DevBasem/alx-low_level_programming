#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *allocate_buffer(char *output_file);
void close_descriptor(int fd);

char *allocate_buffer(char *output_file)
{
	char *output_buffer;

	output_buffer = malloc(sizeof(char) * 1024);

	if (output_buffer == NULL)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", output_file);
		exit(99);
	}

	return (output_buffer);
}

void close_descriptor(int descriptor)
{
	int result;

	result = close(descriptor);

	if (result == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close descriptor %d\n", descriptor);
		exit(100);
	}
}

int main(int num_args, char *args[])
{
	int source, destination, read_bytes, write_bytes;
	char *output_buffer;

	if (num_args != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp source_file destination_file\n");
		exit(97);
	}

	output_buffer = allocate_buffer(args[2]);
	source = open(args[1], O_RDONLY);
	read_bytes = read(source, output_buffer, 1024);
	destination = open(args[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do
	{
		if (source == -1 || read_bytes == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't read from file %s\n", args[1]);
			free(output_buffer);
			exit(98);
		}

		write_bytes = write(destination, output_buffer, read_bytes);
		if (destination == -1 || write_bytes == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't write to %s\n", args[2]);
			free(output_buffer);
			exit(99);
		}

		read_bytes = read(source, output_buffer, 1024);
		destination = open(args[2], O_WRONLY | O_APPEND);

	} while (read_bytes > 0);

	free(output_buffer);
	close_descriptor(source);
	close_descriptor(destination);

	return (0);
}
