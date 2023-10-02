#include "main.h"
#include <elf.h>

void print_elf_header_info(Elf64_Ehdr *header) {
	int i, osabi, type;

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++) {
		printf("%02x ", header->e_ident[i]);
	}
	printf("\n");

	printf("  Class:                            ELF%d\n", header->e_ident[EI_CLASS] == ELFCLASS64 ? 64 : 32);
	printf("  Data:                             %s\n", header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
	printf("  Version:                          %d (current)\n", header->e_ident[EI_VERSION]);

	printf("  OS/ABI:                           ");
	osabi = header->e_ident[EI_OSABI];
	switch (osabi) {
		case ELFOSABI_SYSV:
			printf("UNIX - System V\n");
			break;
		default:
			printf("Other\n");
			break;
	}

	printf("  ABI Version:                      %d\n", header->e_ident[EI_ABIVERSION]);

	printf("  Type:                             ");
	type = header->e_type;
	switch (type) {
		case ET_NONE:
			printf("NONE (None)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("Other\n");
			break;
	}

	printf("  Entry point address:              0x%lx\n", header->e_entry);
}

int main(int argc, char *argv[]) {
	const char *filename;
	int fd;
	Elf64_Ehdr header;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		return 98;
	}
	filename = argv[1];
	fd = open(filename, O_RDONLY);

	if (fd == -1) {
		perror("Error opening file");
		return 98;
	}

	if (read(fd, &header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr)) {
		perror("Error reading ELF header");
		close(fd);
		return 98;
	}

	if (header.e_ident[EI_MAG0] != ELFMAG0 || header.e_ident[EI_MAG1] != ELFMAG1 ||
			header.e_ident[EI_MAG2] != ELFMAG2 || header.e_ident[EI_MAG3] != ELFMAG3) {
		fprintf(stderr, "Error: %s is not an ELF file\n", filename);
		close(fd);
		return 98;
	}

	print_elf_header_info(&header);
	close(fd);

	return 0;
}
