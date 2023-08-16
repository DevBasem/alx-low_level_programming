#include "main.h"
/**
 * this function prints out a random number
 * and checks if the number is positive or
 * negative or equal to zero
 */
void positive_or_negative(int n)
{
if (n > 0)
printf("%i is positive\n", n);
else if (n < 0)
printf("%i is negative\n", n);
else
printf("%i is zero\n", n);
}
