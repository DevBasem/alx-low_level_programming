#include "main.h"
void checkElf(unsigned char *eIdent);
void printMagicNumbers(unsigned char *eIdent);
void printClass(unsigned char *eIdent);
void printData(unsigned char *eIdent);
void printVersion(unsigned char *eIdent);
void printOSABI(unsigned char *eIdent);
void printABI(unsigned char *eIdent);
void printType(unsigned int eType, unsigned char *eIdent);
void printEntryPoint(unsigned long int eEntry, unsigned char *eIdent);
void closeFile(int fileDescriptor);

/**
 * checkElf - Checks if a file is an ELF file.
 * @eIdent: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file - exit code 98.
 */
void checkElf(unsigned char *eIdent)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (eIdent[index] != 127 &&
				eIdent[index] != 'E' &&
				eIdent[index] != 'L' &&
				eIdent[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * printMagicNumbers - Prints the magic numbers of an ELF header.
 * @eIdent: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Magic numbers are separated by spaces.
 */
void printMagicNumbers(unsigned char *eIdent)
{
	int index;

	printf(" Magic: ");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", eIdent[index]);

		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * printClass - Prints the class of an ELF header.
 * @eIdent: A pointer to an array containing the ELF class.
 */
void printClass(unsigned char *eIdent)
{
	printf(" Class: ");

	switch (eIdent[EI_CLASS])
	{
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
			printf("<unknown: %x>\n", eIdent[EI_CLASS]);
	}
}

/**
 * printData - Prints the data of an ELF header.
 * @eIdent: A pointer to an array containing the ELF class.
 */
void printData(unsigned char *eIdent)
{
	printf(" Data: ");

	switch (eIdent[EI_DATA])
	{
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
			printf("<unknown: %x>\n", eIdent[EI_CLASS]);
	}
}

/**
 * printVersion - Prints the version of an ELF header.
 * @eIdent: A pointer to an array containing the ELF version.
 */
void printVersion(unsigned char *eIdent)
{
	printf(" Version: %d",
			eIdent[EI_VERSION]);

	switch (eIdent[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)\n");
			break;
		default:
			printf("\n");
			break;
	}
}

/**
 * printOSABI - Prints the OS/ABI of an ELF header.
 * @eIdent: A pointer to an array containing the ELF version.
 */
void printOSABI(unsigned char *eIdent)
{
	printf(" OS/ABI: ");

	switch (eIdent[EI_OSABI])
	{
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
			printf("<unknown: %x>\n", eIdent[EI_OSABI]);
	}
}

/**
 * printABI - Prints the ABI version of an ELF header.
 * @eIdent: A pointer to an array containing the ELF ABI version.
 */
void printABI(unsigned char *eIdent)
{
	printf(" ABI Version: %d\n",
			eIdent[EI_ABIVERSION]);
}

/**
 * printType - Prints the type of an ELF header.
 * @eType: The ELF type.
 * @eIdent: A pointer to an array containing the ELF class.
 */
void printType(unsigned int eType, unsigned char *eIdent)
{
	if (eIdent[EI_DATA] == ELFDATA2MSB)
		eType >>= 8;

	printf(" Type: ");

	switch (eType)
	{
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
			printf("<unknown: %x>\n", eType);
	}
}

/**
 * printEntryPoint - Prints the entry point of an ELF header.
 * @eEntry: The address of the ELF entry point.
 * @eIdent: A pointer to an array containing the ELF class.
 */
void printEntryPoint(unsigned long int eEntry, unsigned char *eIdent)
{
	printf(" Entry point address: ");

	if (eIdent[EI_DATA] == ELFDATA2MSB)
	{
		eEntry = ((eEntry << 8) & 0xFF00FF00) |
			((eEntry >> 8) & 0xFF00FF);
		eEntry = (eEntry << 16) | (eEntry >> 16);
	}

	if (eIdent[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)eEntry);
	else
		printf("%#lx\n", eEntry);
}

/**
 * closeFile - Closes an ELF file.
 * @fileDescriptor: The file descriptor of the ELF file.
 *
 * Description: If the file cannot be closed - exit code 98.
 */
void closeFile(int fileDescriptor)
{
	if (close(fileDescriptor) == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't close fd %d\n", fileDescriptor);
		exit(98);
	}
}

/**
 * main - Displays the information contained in the
 * ELF header at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the file is not an ELF File or
 * the function fails - exit code 98.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int fileDescriptor, readResult;

	fileDescriptor = open(argv[1], O_RDONLY);
	if (fileDescriptor == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		closeFile(fileDescriptor);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	readResult = read(fileDescriptor, header, sizeof(Elf64_Ehdr));
	if (readResult == -1)
	{
		free(header);
		closeFile(fileDescriptor);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	checkElf(header->e_ident);
	printf("ELF Header:\n");
	printMagicNumbers(header->e_ident);
	printClass(header->e_ident);
	printData(header->e_ident);
	printVersion(header->e_ident);
	printOSABI(header->e_ident);
	printABI(header->e_ident);
	printType(header->e_type, header->e_ident);
	printEntryPoint(header->e_entry, header->e_ident);

	free(header);
	closeFile(fileDescriptor);
	return 0;
}
