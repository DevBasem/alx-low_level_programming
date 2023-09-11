#include "dog.h"
/**
 * init_dog - initialize a variable of type struct dog.
 * @d: positive number of bytes.
 * @name: positive number of bytes.
 * @age: positive number of bytes.
 * @owner: positive number of bytes.
 *
 * Return: Nothing.
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
	d = malloc(sizeof(struct dog));
	d->name = name;
	d->age = age;
	d->owner = owner;
}
