#include "dog.h"
/**
 * print_dog - prints a struct dog
 * @d: name of te dog.
 *
 * Return: Nothing.
 */
void print_dog(struct dog *d)
{
	if (d == NULL)
	return;
	if (d->name != NULL)
	{
		printf("Name: %s\n", d->name);
	}
	else
	{
		d->name = "(nil)";
	}
	printf("Age: %f\n", d->age);
	if (d->owner != NULL)
	{
		printf("Owner: %s\n", d->owner);
	}
	else
	{
		d->owner = "(nil)";
	}
}
