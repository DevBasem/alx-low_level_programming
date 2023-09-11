#include "dog.h"
/**
 * *new_dog - creates a new dog.
 * @name: positive number of bytes.
 * @age: positive number of bytes.
 * @owner: positive number of bytes.
 *
 * Return: Nothing.
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *cuteDog;
	int nameLen;
	int ownerLen;

	nameLen = strlen(name);
	ownerLen = strlen(owner);
	cuteDog = malloc(sizeof(dog_t));
	if (cuteDog == NULL)
	{
		return (NULL);
	}
	cuteDog->name = malloc((nameLen + 1) * sizeof(char));
	if (cuteDog->name == NULL)
	{
		free(cuteDog);
		return (NULL);
	}
	cuteDog->owner = malloc((ownerLen + 1) * sizeof(char));
	if (cuteDog->owner == NULL)
	{
		free(cuteDog);
		free(cuteDog->name);
		return (NULL);
	}
	strcpy(cuteDog->name, name);
	strcpy(cuteDog->owner, owner);
	cuteDog->age = age;
	return (cuteDog);
}
