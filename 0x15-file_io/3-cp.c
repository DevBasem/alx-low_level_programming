#include "main.h"
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

void exit_with_error(int code, const char *format, const char *arg) {
	if (arg != NULL) {
		dprintf(STDERR_FILENO, format, arg);
	} else {
		dprintf(STDERR_FILENO, "%s", format);
	}
	exit(code);
}

int main(int argc, char *argv[]) {
	const char *file_from, *file_to;
	int fd_from, fd_to;
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read, bytes_written;

	if (argc != 3) {
		exit_with_error(97, "Usage: cp file_from file_to\n", NULL);
	}

	file_from = argv[1];
	file_to = argv[2];

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1) {
		exit_with_error(98, "Error: Can't read from file %s\n", file_from);
	}

	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd_to == -1) {
		exit_with_error(99, "Error: Can't write to %s\n", file_to);
	}

	while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0) {
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1) {
			exit_with_error(99, "Error: Can't write to %s\n", file_to);
		}
	}

	if (bytes_read == -1) {
		exit_with_error(98, "Error: Can't read from file %s\n", file_from);
	}

	if (close(fd_from) == -1) {
		exit_with_error(100, "Error: Can't close fd %d\n", NULL);
	}

	if (close(fd_to) == -1) {
		exit_with_error(100, "Error: Can't close fd %d\n", NULL);
	}

	return 0;
}
