#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void checkIsElfFile(unsigned char *magicNumbers);
void printMagicNumbers(unsigned char *magicNumbers);
void printElfClass(unsigned char *magicNumbers);
void printDataEncoding(unsigned char *magicNumbers);
void printElfVersion(unsigned char *magicNumbers);
void printOsAbi(unsigned char *magicNumbers);
void printAbiVersion(unsigned char *magicNumbers);
void printElfType(unsigned int elfType, unsigned char *magicNumbers);
void printEntryPoint(unsigned long int entryPoint, unsigned char *magicNumbers);
void closeElfFile(int fileDescriptor);

void checkIsElfFile(unsigned char *magicNumbers) {
	int index;

	for (index = 0; index < 4; index++) {
		if (magicNumbers[index] != 127 &&
				magicNumbers[index] != 'E' &&
				magicNumbers[index] != 'L' &&
				magicNumbers[index] != 'F') {
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

void printMagicNumbers(unsigned char *magicNumbers) {
	int index;

	printf(" Magic: ");

	for (index = 0; index < EI_NIDENT; index++) {
		printf("%02x", magicNumbers[index]);

		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

void printElfClass(unsigned char *magicNumbers) {
	printf(" Class: ");

	switch (magicNumbers[EI_CLASS]) {
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", magicNumbers[EI_CLASS]);
	}
}

void printDataEncoding(unsigned char *magicNumbers) {
	printf(" Data: ");

	switch (magicNumbers[EI_DATA]) {
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", magicNumbers[EI_CLASS]);
	}
}

void printElfVersion(unsigned char *magicNumbers) {
	printf(" Version: %d", magicNumbers[EI_VERSION]);

	switch (magicNumbers[EI_VERSION]) {
		case EV_CURRENT:
			printf(" (current)\n");
			break;
		default:
			printf("\n");
			break;
	}
}

void printOsAbi(unsigned char *magicNumbers) {
	printf(" OS/ABI: ");

	switch (magicNumbers[EI_OSABI]) {
		case ELFOSABI_NONE:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
		default:
			printf("<unknown: %x>\n", magicNumbers[EI_OSABI]);
	}
}

void printAbiVersion(unsigned char *magicNumbers) {
	printf(" ABI Version: %d\n", magicNumbers[EI_ABIVERSION]);
}

void printElfType(unsigned int elfType, unsigned char *magicNumbers) {
	if (magicNumbers[EI_DATA] == ELFDATA2MSB)
		elfType >>= 8;

	printf(" Type: ");

	switch (elfType) {
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
			printf("<unknown: %x>\n", elfType);
	}
}

void printEntryPoint(unsigned long int entryPoint, unsigned char *magicNumbers) {
	printf(" Entry point address: ");

	if (magicNumbers[EI_DATA] == ELFDATA2MSB) {
		entryPoint = ((entryPoint << 8) & 0xFF00FF00) |
			((entryPoint >> 8) & 0xFF00FF);
		entryPoint = (entryPoint << 16) | (entryPoint >> 16);
	}

	if (magicNumbers[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)entryPoint);
	else
		printf("%#lx\n", entryPoint);
}

void closeElfFile(int fileDescriptor) {
	if (close(fileDescriptor) == -1) {
		dprintf(STDERR_FILENO, "Error: Can't close file descriptor %d\n", fileDescriptor);
		exit(98);
	}
}

int main(int __attribute__((__unused__)) argc, char *argv[]) {
	Elf64_Ehdr *header;
	int fileDescriptor, readResult;

	fileDescriptor = open(argv[1], O_RDONLY);
	if (fileDescriptor == -1) {
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL) {
		closeElfFile(fileDescriptor);
		dprintf(STDERR_FILENO, "Error: Can't allocate memory for ELF header\n");
		exit(98);
	}

	readResult = read(fileDescriptor, header, sizeof(Elf64_Ehdr));
	if (readResult == -1) {
		free(header);
		closeElfFile(fileDescriptor);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	checkIsElfFile(header->e_ident);
	printf("ELF Header:\n");
	printMagicNumbers(header->e_ident);
	printElfClass(header->e_ident);
	printDataEncoding(header->e_ident);
	printElfVersion(header->e_ident);
	printOsAbi(header->e_ident);
	printAbiVersion(header->e_ident);
	printElfType(header->e_type, header->e_ident);
	printEntryPoint(header->e_entry, header->e_ident);

	free(header);
	closeElfFile(fileDescriptor);
	return 0;
}
