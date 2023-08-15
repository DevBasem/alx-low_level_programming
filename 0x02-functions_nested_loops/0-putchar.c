#include <stdio.h>
/**
 ** main - Entry point
 **
 ** Return: Always 0 (Success)
 **
 ** this program prints out _putchar
 **/
int main(void)
{
int i;
char msg[] = "_putchar";
for (i = 0; i < 8; i++)
{
putchar (msg[i]);
}
putchar ('\n');
return (0);
}
