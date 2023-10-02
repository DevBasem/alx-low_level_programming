#include "main.h"

/**
 * print_error - Print an error message to stderr and exit the program with exit code 98.
 * @message: The error message to be printed.
 */
void print_error(const char* message) {
	fprintf(stderr, "Error: %s\n", message);
	exit(98);
}

/**
 * print_elf_header - Print the contents of an ELF header to stdout.
 * @elf_header: A pointer to the Elf64_Ehdr structure containing the ELF header.
 */
void print_elf_header(const Elf64_Ehdr* elf_header) {
	int i;
	printf("Magic:   ");
	for (i = 0; i < EI_NIDENT; i++) {
		printf("%02x ", elf_header->e_ident[i]);
	}
	printf("\nClass:   %s\n", (elf_header->e_ident[EI_CLASS] == ELFCLASS32) ? "ELF32" : "ELF64");
	printf("Data:    %s\n", (elf_header->e_ident[EI_DATA] == ELFDATA2LSB) ? "2's complement, little endian" : "unknown");
	printf("Version: %d (current)\n", elf_header->e_ident[EI_VERSION]);
	printf("OS/ABI:  %s\n", (elf_header->e_ident[EI_OSABI] == ELFOSABI_SYSV) ? "UNIX - System V" : "unknown");
	printf("ABI Version: %d\n", elf_header->e_ident[EI_ABIVERSION]);
	printf("Type:    %d (EXEC)\n", elf_header->e_type);
	printf("Entry point address: 0x%lx\n", (unsigned long)elf_header->e_entry);
}

/**
 * main - The main entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings representing the command-line arguments.
 *
 * Return: Always 0.
 */
int main(int argc, char* argv[]) {
	const char* filename;
	int fd;
	Elf64_Ehdr elf_header;

	if (argc != 2) {
		print_error("Usage: elf_header elf_filename");
	}

	filename = argv[1];
	fd = open(filename, O_RDONLY);
	if (fd == -1) {
		print_error("Failed to open the file");
	}

	if (read(fd, &elf_header, sizeof(elf_header)) != sizeof(elf_header)) {
		print_error("Failed to read ELF header");
	}

	if (elf_header.e_ident[EI_MAG0] != ELFMAG0 || 
			elf_header.e_ident[EI_MAG1] != ELFMAG1 ||
			elf_header.e_ident[EI_MAG2] != ELFMAG2 ||
			elf_header.e_ident[EI_MAG3] != ELFMAG3) {
		print_error("Not an ELF file");
	}

	print_elf_header(&elf_header);

	close(fd);
	return 0;
}
