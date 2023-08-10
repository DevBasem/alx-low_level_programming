#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
int x;
double y;
char z;
printf("the size of an int is: %lu.\n", (unsigned long)sizeof(x));
printf("the size of an double is: %lu.\n", (unsigned long)sizeof(y));
printf("the size of a char is: %lu.\n", (unsigned long)sizeof(z));
return (0);
}
