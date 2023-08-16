#include <stdio.h>
/**
 * main - check the code.
 *
 * Return: Always 0.
 */
int main(void)
{
float tS;
unsigned long fib1 = 0, fib2 = 1, sum;
while (1)
{
sum = fib1 + fib2;
if (sum > 4000000)
break;
if ((sum % 2) == 0)
tS += sum;
fib1 = fib2;
fib2 = sum;
}
printf("%.0f\n", tS);
return (0);
}
