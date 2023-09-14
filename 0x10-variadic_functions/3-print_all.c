#include "variadic_functions.h"

/**
 * print_all -  prints anything.
 * @format: list of types of arguments.
 *
 * Return: Nothing.
 */
void print_all(const char * const format, ...)
{
	int index = 0;
	char *current_str, *separator = "";
	va_list args;

	va_start(args, format);

	if (format)
	{
		while (format[index])
		{
			switch (format[index])
			{
				case 'c':
					printf("%s%c", separator, va_arg(args, int));
					break;
				case 'i':
					printf("%s%d", separator, va_arg(args, int));
					break;
				case 'f':
					printf("%s%f", separator, va_arg(args, double));
					break;
				case 's':
					current_str = va_arg(args, char *);
					if (!current_str)
						current_str = "(nil)";
					printf("%s%s", separator, current_str);
					break;
				default:
					index++;
					continue;
			}
			separator = ", ";
			index++;
		}
	}

	printf("\n");
	va_end(args);
}
