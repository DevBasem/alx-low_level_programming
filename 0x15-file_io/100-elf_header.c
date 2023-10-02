#include "main.h"
typedef struct {
	uint8_t e_ident[16];
	uint16_t e_type;
	uint16_t e_machine;
	uint32_t e_version;
	uint64_t e_entry;
	uint64_t e_phoff;
	uint64_t e_shoff;
	uint32_t e_flags;
	uint16_t e_ehsize;
	uint16_t e_phentsize;
	uint16_t e_phnum;
	uint16_t e_shentsize;
	uint16_t e_shnum;
	uint16_t e_shstrndx;
} ElfHeader;

void print_elf_header(ElfHeader *header) {
	int i;

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < 16; i++) {
		printf("%02x ", header->e_ident[i]);
	}
	printf("\n");
	printf("  Class:                             ");
	if (header->e_ident[4] == 1) {
		printf("ELF32\n");
	} else if (header->e_ident[4] == 2) {
		printf("ELF64\n");
	} else {
		printf("Invalid ELF class\n");
		exit(98);
	}
	printf("  Data:                              ");
	if (header->e_ident[5] == 1) {
		printf("2's complement, little endian\n");
	} else if (header->e_ident[5] == 2) {
		printf("2's complement, big endian\n");
	} else {
		printf("Invalid data encoding\n");
		exit(98);
	}
	printf("  Version:                           %u (current)\n", header->e_version);
	printf("  OS/ABI:                            ");
	switch (header->e_ident[7]) {
		case 0:
			printf("UNIX - System V\n");
			break;
		case 6:
			printf("UNIX - Solaris\n");
			break;
		case 9:
			printf("UNIX - NetBSD\n");
			break;
		default:
			printf("<unknown: %u>\n", header->e_ident[7]);
			break;
	}
	printf("  ABI Version:                       %u\n", header->e_ident[8]);
	printf("  Type:                              ");
	switch (header->e_type) {
		case 1:
			printf("REL (Relocatable file)\n");
			break;
		case 2:
			printf("EXEC (Executable file)\n");
			break;
		case 3:
			printf("DYN (Shared object file)\n");
			break;
		default:
			printf("Unknown type\n");
			exit(98);
	}
	printf("  Entry point address:               0x%lx\n", header->e_entry);
}

int main(int argc, char *argv[]) {
	int fd;
	ElfHeader header;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		return 98;
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1) {
		perror("Error opening file");
		return 98;
	}

	if (read(fd, &header, sizeof(header)) != sizeof(header)) {
		perror("Error reading ELF header");
		close(fd);
		return 98;
	}

	if (memcmp(header.e_ident, "\x7f""ELF", 4) != 0) {
		fprintf(stderr, "Not an ELF file\n");
		close(fd);
		return 98;
	}

	print_elf_header(&header);
	close(fd);

	return 0;
}
