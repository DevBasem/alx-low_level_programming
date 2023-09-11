#ifndef HEADER_FILE
#define HEADER_FILE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
/**
 * struct dog - object for dog.
 * @name: name of the cute dog.
 * @age: age of the cute dog.
 * @owner: owner of the cute dog.
 *
 * Description: cute dog home.
 */
struct dog
{
char *name;
float age;
char *owner;
};
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
#endif
