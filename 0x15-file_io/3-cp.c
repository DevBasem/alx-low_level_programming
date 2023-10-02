#include "main.h"

/**
 * error_exit - Prints an error message and exits with the given code.
 * @code: The exit code.
 * @format: The format string for the error message.
 * @...: Additional arguments for the format string.
 */
void error_exit(int code, const char *format, ...)
{
	va_list args;

	va_start(args, format);
	vfprintf(stderr, format, args);
	va_end(args);
	exit(code);
}

/**
 * main - Copies the content of a file to another file.
 * @ac: The number of arguments.
 * @av: An array of argument strings.
 *
 * Return: 0 on success, or the appropriate error code.
 */
int main(int ac, char **av)
{
	int fd_from, fd_to;
	ssize_t n;
	char buffer[BUF_SIZE];

	if (ac != 3)
		error_exit(97, "Usage: cp file_from file_to\n");

	fd_from = open(av[1], O_RDONLY);
	if (fd_from == -1)
		error_exit(98, "Error: Can't read from file %s\n", av[1]);

	fd_to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd_to == -1)
		error_exit(99, "Error: Can't write to %s\n", av[2]);

	while ((n = read(fd_from, buffer, BUF_SIZE)) > 0)
	{
		if (write(fd_to, buffer, n) != n)
			error_exit(99, "Error: Can't write to %s\n", av[2]);
	}

	if (n == -1)
		error_exit(98, "Error: Can't read from file %s\n", av[1]);

	if (close(fd_from) == -1 || close(fd_to) == -1)
		error_exit(100, "Error: Can't close fd\n");

	return (0);
}
