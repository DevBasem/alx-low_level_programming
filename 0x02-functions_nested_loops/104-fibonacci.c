#include <stdio.h>
/**
 * nLength - checks the length of the number.
 * @n: The number to check
 *
 * Return: digits number
 */
int nLength(int n)
{
int length = 0;
if (!n)
return (1);
while (n)
{
n = n / 10;
length += 1;
}
return (length);
}
/**
 * main - check the code.
 *
 * Return: Always 0.
 */
int main(void)
{
int c, i10s;
unsigned long f1 = 1, f2 = 2, sum, max = 100000000, f1o = 0, f2o = 0, sumo = 0;
for (c = 1; c <= 98; c++)
{
if (f1o > 0)
printf("%lu", f1o);
i10s = nLength(max) - 1 - nLength(f1);
while (f1o > 0 && i10s > 0)
{
printf("%d", 0);
i10s--;
}
printf("%lu", f1);
sum = (f1 + f2) % max;
f1 = f2;
f1o = f2o;
f2 = sum;
f2o = sumo;
if (c != 98)
printf(", ");
else
printf("\n");
}
return (0);
}
