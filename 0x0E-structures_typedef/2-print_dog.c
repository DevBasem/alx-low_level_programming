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
	d = malloc(sizeof(struct dog));
	printf("Name: %s\n", d->name);
	printf("Age: %f\n", d->age);
	printf("Owner: %s\n", d->owner);
}
