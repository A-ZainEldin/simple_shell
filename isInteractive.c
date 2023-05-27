#include "shell.h"

/**
 * interactive - if true it returns true that shell is in interactive mode
 * @info: all it deos structs adress.
 *
 * Return: 1 means itas in interactive mode 0 means its not.
 */

int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - all it does is checks if char is delimeter
 * @c: to char check.
 * @delim: the string of delimeter
 * Return: 0 for false and 1 for true
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - checks if its alphabatical char or not
 * @c: To input the good character
 * Return: 1 only and only if its alphatic 0 if smth else
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - converts from a string to a weird integer
 * @s: the string is going to be converted
 * Return: 0 will be there if no numberss in the strings, wil be conv otherwise
 */

int _atoi(char *s)
{
	int l, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (l = 0; s[l] != '\0' && flag != 2; l++)
	{
		if (s[l] == '-')
			sign *= -1;

		if (s[l] >= '0' && s[l] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[l] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

