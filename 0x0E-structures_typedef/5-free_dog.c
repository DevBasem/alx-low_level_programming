#include "dog.h"
/**
 * free_dog - free on demand function.
 * @d: the dog struct to be freed.
 *
 * Return: Nothing.
 */
void free_dog(dog_t *d)
{
	if (d)
	{
	free(d->name);
	free(d->owner);
	free(d);
	}
}
