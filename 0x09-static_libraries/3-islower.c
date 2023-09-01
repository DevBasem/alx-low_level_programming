#include "main.h"
/**
 * _islower - checks for lowercase character.
 * @c: The character to print
 *
 * Return: 1 if lowercase or 0 if other
 */
int _islower(int c)
{
if (c >= 97 && c <= 122)
return (1);
else
return (0);
}
