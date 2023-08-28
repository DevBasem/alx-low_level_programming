#include "main.h"
/**
 * set_string - sets the value of a pointer to a char.
 * @s: string to copy from.
 * @to: copy to.
 *
 * Return: pointer value changed.
 */
void set_string(char **s, char *to)
{
	*s = to;
}
