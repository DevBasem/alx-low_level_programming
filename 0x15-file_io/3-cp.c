#include "main.h"
#include <sys/stat.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024

void print_error_and_exit(int code, const char *message) {
    dprintf(STDERR_FILENO, "Error: %s\n", message);
    exit(code);
}

int main(int argc, char *argv[]) {
    const char *file_from;
    const char *file_to;
    int fd_from;
    int fd_to;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    if (argc != 3) {
        print_error_and_exit(97, "Usage: cp file_from file_to");
    }

    file_from = argv[1];
    file_to = argv[2];

    fd_from = open(file_from, O_RDONLY);
    if (fd_from == -1) {
        print_error_and_exit(98, "Can't read from file");
    }

    fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd_to == -1) {
        close(fd_from);
        print_error_and_exit(99, "Can't write to file");
    }

    while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0) {
        if (write(fd_to, buffer, bytes_read) != bytes_read) {
            close(fd_from);
            close(fd_to);
            print_error_and_exit(99, "Can't write to file");
        }
    }

    if (bytes_read == -1) {
        close(fd_from);
        close(fd_to);
        print_error_and_exit(98, "Can't read from file");
    }

    if (close(fd_from) == -1) {
        print_error_and_exit(100, "Can't close fd");
    }

    if (close(fd_to) == -1) {
        print_error_and_exit(100, "Can't close fd");
    }

    return 0;
}
