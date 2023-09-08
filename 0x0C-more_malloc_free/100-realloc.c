#include "main.h"
/**
 * *_realloc -  reallocates a memory block using malloc and free.
 * @ptr: memory block to allocate.
 * @old_size: ptr size.
 * @new_size: targeted size.
 *
 * Return: Nothing.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;
	unsigned int i;

	if (new_size == old_size)
	{
		return (ptr);
	}

	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = malloc(new_size);

	if (!new_ptr)
	{
		return (NULL);
	}

	if (ptr)
	{
		unsigned int min_size = new_size < old_size ? new_size : old_size;

		for (i = 0; i < min_size; i++)
		{
			((char *)new_ptr)[i] = ((char *)ptr)[i];
		}
		free(ptr);
	}

	return (new_ptr);
}
