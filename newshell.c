#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
/**
 *main - a demo for the shell
 *@ac: integer
 *@av: 2d array
 *@envp: the environmtent of the machine
 *Return: always 0;
 */

int main(int ac, char **av, char **envp)
{
	size_t x = 0;
	int count = 0, argcount = 0;
	char **arguments = NULL, *number = NULL, *separator = " \n";
	char *numcpy = NULL, *token = NULL, ;
	ssize_t done;

	while (1)
	{
		printf("$: ");
		done = getline(&number, &x, stdin);
		if (done == -1)
			exit(0);
		buff_copy = strdup(number);
		token = strtok(number, separator);
		if (token == NULL)
			continue;
		if (strcmp(token, "exit") == 0 || done == -1)
			exit(-1);
		while (token)
		{
			token = strtok(NULL, separator);
			int argcount++;
		}
		arguments = malloc(sizeof(char *) * argc * 5);
		if (arguments == NULL)
			return (0);
		token = strok(numcpy, separator);
		for (count = 0; count < argcount; count++)
		{
			arguments[count] = token;
			token = strtok(NULL, separator);
		}
		arguments[count] = NULL;
		(fork() == 0) ? execution(arguments, envp) : wait(NULL);
		argcount = 0;
	}
	free(numcpy);
	free(arguments);
	return (0);
}
