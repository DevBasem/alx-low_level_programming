#include "main.h"
/**
 * *_calloc -  allocates memory for an array of nmemb elements of size bytes.
 * @nmemb: number of elements.
 * @size: size in bytes.
 *
 * Return: Nothing.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	size_t total_size;
	void *ptr;

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}

	total_size = (size_t)nmemb * size;
	ptr = malloc(total_size);

	if (ptr == NULL)
	{
		return (NULL);
	}

	memset(ptr, 0, total_size);

	return (ptr);
}
