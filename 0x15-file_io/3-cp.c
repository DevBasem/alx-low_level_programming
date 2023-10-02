#include "main.h"

/**
 * exit_with_error - Prints an error message and exits with the given code.
 * @code: The exit code.
 * @format: The format string for the error message.
 * @...: Additional arguments for the format string.
 */
void exit_with_error(int code, const char *format, ...)
{
    va_list args;

    va_start(args, format);
    dprintf(STDERR_FILENO, format, args);
    va_end(args);
    exit(code);
}

/**
 * create_buffer - Allocates a buffer for reading/writing.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *create_buffer()
{
    char *buffer = malloc(BUFFER_SIZE);

    if (buffer == NULL)
    {
        exit_with_error(99, "Error: Unable to allocate buffer\n");
    }

    return (buffer);
}

/**
 * close_file_descriptor - Closes a file descriptor.
 * @fd: The file descriptor to be closed.
 */
void close_file_descriptor(int fd)
{
    if (close(fd) == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close file descriptor %d\n", fd);
        exit(100);
    }
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success, or the appropriate error code on failure.
 */
int main(int argc, char *argv[])
{
    int source_fd, destination_fd;
    ssize_t bytes_read;
    char *buffer;

    if (argc != 3)
    {
        exit_with_error(97, "Usage: cp source_file destination_file\n");
    }

    buffer = create_buffer();

    source_fd = open(argv[1], O_RDONLY);
    if (source_fd == -1)
    {
        exit_with_error(98, "Error: Can't read from source file %s\n", argv[1]);
    }

    destination_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (destination_fd == -1)
    {
        exit_with_error(99, "Error: Can't write to destination file %s\n", argv[2]);
    }

    while ((bytes_read = read(source_fd, buffer, BUFFER_SIZE)) > 0)
    {
        ssize_t bytes_written = write(destination_fd, buffer, bytes_read);
        if (bytes_written != bytes_read)
        {
            exit_with_error(99, "Error: Incomplete write to destination file %s\n", argv[2]);
        }
    }

    if (bytes_read == -1)
    {
        exit_with_error(98, "Error: Can't read from source file %s\n", argv[1]);
    }

    close_file_descriptor(source_fd);
    close_file_descriptor(destination_fd);
    free(buffer);

    return (0);
}
