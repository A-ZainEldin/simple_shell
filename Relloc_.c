#include "shell.h"

/**
 * _memset - will fill the memo with bytes…
 * @s: memo area..
 * @b: byte filled with *s
 * @n: bytes counter to put them
 * Return: a pointer for memo area(s)..
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * ffree - will free some space from a string to a string.
 * @pp: the string to a string.
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - will put the new location.
 * @ptr: new location for prev. malloc.
 * @old_size: the byte size
 * @new_size: the byte size
 *
 * Return: points to the nameen
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}


