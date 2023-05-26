#include "shell.h"

/**
 * bfree - will free a pointer and will null the location
 * @ptr: to free a location
 *
 * Return: 1 if successful 0 if failed
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}


