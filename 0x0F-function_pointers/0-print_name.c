#include "function_pointers.h"

/**
 * print_name - a call back function.
 * @name: name of the person.
 * @f: a function to print a name.
 *
 * Return: Nothing.
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
	return;

	(f(name));
}
