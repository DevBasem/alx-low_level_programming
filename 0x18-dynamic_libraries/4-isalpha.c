#include "main.h"
/**
 * _isalpha - checks for lowercase character.
 * @c: The character to print
 *
 * Return: 1 if alpha or 0 if other
 */
int _isalpha(int c)
{
if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
return (1);
else
return (0);
}
