#include "main.h"

void check_elf(unsigned char *e_ident);
void print_header_info(Elf64_Ehdr *header);

void check_elf(unsigned char *e_ident)
{
	if (e_ident[EI_MAG0] != ELFMAG0 || e_ident[EI_MAG1] != ELFMAG1 ||
			e_ident[EI_MAG2] != ELFMAG2 || e_ident[EI_MAG3] != ELFMAG3) {
		fprintf(stderr, "Error: Not an ELF file\n");
		exit(98);
	}
}

void print_header_info(Elf64_Ehdr *header)
{
	int i;

	printf("ELF Header:\n");
	printf(" Magic: ");
	for (i = 0; i < EI_NIDENT; i++) {
		printf("%02x%s", header->e_ident[i], (i == EI_NIDENT - 1) ? "\n" : " ");
	}
	printf(" Class: %s\n", (header->e_ident[EI_CLASS] == ELFCLASS32) ? "ELF32" : "ELF64");
	printf(" Data: %s\n", (header->e_ident[EI_DATA] == ELFDATA2LSB) ? "2's complement, little endian" : 
			(header->e_ident[EI_DATA] == ELFDATA2MSB) ? "2's complement, big endian" : "Unknown");
	printf(" Version: %d %s\n", header->e_ident[EI_VERSION], 
			(header->e_ident[EI_VERSION] == EV_CURRENT) ? "(current)" : "");
	printf(" OS/ABI: ");
	switch (header->e_ident[EI_OSABI]) {
		case ELFOSABI_NONE: printf("UNIX - System V\n"); break;
		case ELFOSABI_HPUX: printf("UNIX - HP-UX\n"); break;
		case ELFOSABI_NETBSD: printf("UNIX - NetBSD\n"); break;
		case ELFOSABI_LINUX: printf("UNIX - Linux\n"); break;
		case ELFOSABI_SOLARIS: printf("UNIX - Solaris\n"); break;
		case ELFOSABI_IRIX: printf("UNIX - IRIX\n"); break;
		case ELFOSABI_FREEBSD: printf("UNIX - FreeBSD\n"); break;
		case ELFOSABI_TRU64: printf("UNIX - TRU64\n"); break;
		case ELFOSABI_ARM: printf("ARM\n"); break;
		case ELFOSABI_STANDALONE: printf("Standalone App\n"); break;
		default: printf("<unknown: %x>\n", header->e_ident[EI_OSABI]); break;
	}
	printf(" ABI Version: %d\n", header->e_ident[EI_ABIVERSION]);
	printf(" Type: ");
	switch (header->e_type) {
		case ET_NONE: printf("NONE (None)\n"); break;
		case ET_REL: printf("REL (Relocatable file)\n"); break;
		case ET_EXEC: printf("EXEC (Executable file)\n"); break;
		case ET_DYN: printf("DYN (Shared object file)\n"); break;
		case ET_CORE: printf("CORE (Core file)\n"); break;
		default: printf("<unknown: %x>\n", header->e_type); break;
	}
	printf(" Entry point address: %#lx\n", header->e_entry);
}

int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr header;
	ssize_t bytes_read;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <ELF file>\n", argv[0]);
		return 1;
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1) {
		perror("Error: Can't open file");
		return 98;
	}

	bytes_read = read(fd, &header, sizeof(Elf64_Ehdr));
	if (bytes_read != sizeof(Elf64_Ehdr)) {
		perror("Error reading ELF header");
		close(fd);
		return 98;
	}

	check_elf(header.e_ident);
	print_header_info(&header);

	close(fd);
	return 0;
}
