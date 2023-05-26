#include "shell.h"

/**
 * _eputs - prints the input string
 * @str: to print out the string
 *
 * Return: will return nothing
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - will write the char c to the stderr
 * @c: to print the char
 *
 * Return: returns 1 if succ..
 * if error -1, and errno is set.
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd - it wil write the char c to the given.
 * @c: the char to printout
 * @fd: the filedisc to write
 *
 * Return: 1if succ..
 * -1 is returned if error
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putsfd - will print a string input
 * @str: the string will be printed
 * @fd: filedescriptor to go to
 *
 * Return: the number of characters.
 */
int _putsfd(char *str, int fd)
{
	int k = 0;

	if (!str)
		return (0);
	while (*str)
	{
		k += _putfd(*str++, fd);
	}
	return (k);
}



