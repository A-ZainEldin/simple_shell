#include "main.h"
/**
 * leave - leaves or quit the loop
 * @argv : argument pass
 * Return: if failed returns -1
 */
int leave(char **argv)
{
	int k;

	if (strcmp(argv[0], "exit") == 0 && argv[1])
	{
	k = atoi(argv[1]);
	return (k);
	}
	else if (strcmp(argv[0], "exit") == 0)
	return (0);
	else

	return (-1);
}
