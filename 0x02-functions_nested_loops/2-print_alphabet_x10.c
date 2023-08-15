#include "main.h"
/**
 * print_alphabet_x10 - this function prints out lowercase alphabet
 * 10 times
 **/
void print_alphabet_x10(void)
{
int i;
int y;
for (y = 0; y < 10; y++)
{
for (i = 97; i <= 122; i++)
{
_putchar (i);
}
_putchar ('\n');
}
}
