#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *allocate_buffer(char *file);
void close_descriptor(int fd);

/**
 * allocate_buffer - Allocates 1024 bytes for a buffer.
 * @file: The name of the file the buffer is associated with.
 *
 * Returns: A pointer to the newly-allocated buffer.
 */
char *allocate_buffer(char *file)
{
    char *buffer = malloc(1024 * sizeof(char));

    if (buffer == NULL)
    {
        dprintf(STDERR_FILENO, "Error: Can't allocate buffer for %s\n", file);
        exit(99);
    }
    return (buffer);
}

/**
 * close_descriptor - Closes a file descriptor.
 * @fd: The file descriptor to be closed.
 */
void close_descriptor(int fd)
{
    if (close(fd) == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
        exit(100);
    }
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of command-line arguments.
 * @argv: An array of pointers to the command-line arguments.
 *
 * Returns: 0 on success.
 *
 * Description: Exits with specific error codes for different failures:
 *   97 - Incorrect number of arguments
 *   98 - Unable to read from file_from
 *   99 - Unable to write to file_to
 *   100 - Unable to close file descriptors
 */
int main(int argc, char *argv[])
{
    int source_fd, destination_fd, bytes_read;
    char *buffer;

    if (argc != 3)
    {
        dprintf(STDERR_FILENO, "Usage: cp source_file destination_file\n");
        exit(97);
    }

    buffer = allocate_buffer(argv[2]);
    source_fd = open(argv[1], O_RDONLY);
    destination_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

    while ((bytes_read = read(source_fd, buffer, 1024)) > 0)
    {
        if (bytes_read == -1 || write(destination_fd, buffer, bytes_read) == -1)
        {
            dprintf(STDERR_FILENO, "Error: File operation failed\n");
            free(buffer);
            exit(99);
        }
    }

    free(buffer);
    close_descriptor(source_fd);
    close_descriptor(destination_fd);

    return (0);
}
