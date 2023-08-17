#include "main.h"
/**
 * print_triangle - prints a triangle on the terminal.
 * @size : is the size of the triangle.
 *
 * Return: triangle.
 */
void print_triangle(int size)
{
	int i;
	int j;
	int k;

	if (size <= 0)
	{
	_putchar ('\n');
	}
	else
	{
	for (i = 1; i <= size; i++)
	{
	for (j = 1; j <= size - i; j++)
	{
	_putchar (' ');
	}
	for (k = i; k >= 1; k--)
	{
	_putchar (35);
	}
	_putchar ('\n');
	}
	}
}
