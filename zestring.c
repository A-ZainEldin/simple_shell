#include "shell.h"

/**
 * _strlen - gives the length of the string
 * @s: the length of the string we will check
 *
 * Return: the length
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _strcmp - compares the two strings.
 * @s1: string 1
 * @s2: string 2
 *
 * Return: (-) if s1 is less than s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - if it needs hatstack
 * @haystack: search
 * @needle: finding the secondary string
 *
 * Return: sees the next location
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - two strings..
 * @dest: the loca. Of the buff..
 * @src: source of buff..
 *
 * Return: points at the buffer location.
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}


