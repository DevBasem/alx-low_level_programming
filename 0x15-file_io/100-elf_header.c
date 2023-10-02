#include "main.h"

/**
 * display_error - Display an error message and exit with status code 98.
 *
 * @message: The error message to be displayed.
 */
void display_error(const char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(98);
}

/**
 * display_elf_header - Display information from
 * the ELF header of a given file.
 *
 * @filename: The name of the ELF file to analyze
 * and display the header information.
 */
void display_elf_header(const char *filename)
{
	ssize_t bytes_read;
	Elf32_Ehdr elf_header;
	int i, magic_match;
	int fd = open(filename, O_RDONLY);

	if (fd == -1)
	{
		display_error("Error opening file");
	}

	bytes_read = read(fd, &elf_header, sizeof(Elf32_Ehdr));
	if (bytes_read != sizeof(Elf32_Ehdr))
		display_error("Error reading ELF header");

	magic_match = memcmp(elf_header.e_ident, ELFMAG, SELFMAG) == 0;
	if (!magic_match)
		display_error("Not an ELF file");

	printf("Magic: ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", elf_header.e_ident[i]);
	}
	printf("\n");
	printf("Class: %s\n", elf_header.e_ident[EI_CLASS] == ELFCLASS32 ?
			"ELF32" : "ELF64");
	printf("Data: %s\n", elf_header.e_ident[EI_DATA] == ELFDATA2LSB ?
			"2's complement, little endian" : "Invalid");
	printf("Version: %d\n", elf_header.e_ident[EI_VERSION]);
	printf("OS/ABI: %d\n", elf_header.e_ident[EI_OSABI]);
	printf("ABI Version: %d\n", elf_header.e_ident[EI_ABIVERSION]);
	printf("Type: %d\n", elf_header.e_type);
	printf("Entry point address: 0x%x\n", elf_header.e_entry);
	close(fd);
}

/**
 * main - Entry point of the program.
 *
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	const char *filename;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		return (1);
	}

	filename = argv[1];
	display_elf_header(filename);

	return (0);
}
