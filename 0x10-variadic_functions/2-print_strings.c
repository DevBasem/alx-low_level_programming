#include "variadic_functions.h"

/**
 * print_strings - prints strings, followed by a new line.
 * @separator: used between strings.
 * @n: number of strings.
 *
 * Return: Nothing.
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;
	const char *str;
	/*void *ptr = NULL;*/

	va_start(args, n);
	for (i = 0; i < n; i++)
	{
		str = va_arg(args, const char*);
		if (str == NULL)
		printf("%p", NULL);
		else
		printf("%s", str);
		if (i != n - 1 && separator != NULL)
			printf("%s", separator);
	}
	va_end(args);
	printf("\n");
}
