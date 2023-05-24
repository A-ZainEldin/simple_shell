#include "main.h"
/**
*environment- returns to the environments list
*@command: the command send by the user
*
*Return: returns null
*/
char *environment(cahr *command)
{
	char *cmd = NULL, *cmd2 = NULL, *elist = NULL;
	char *etoken =  NULL;
	int xlength, ylength;
	struct stat info;

	cmd = getenv("PATH");
	cmd2 = strdup(cmd);
	xlength = strlen(command);
	etoken = strtok(cmd2, ":");
	while (etoken)
	{
	ylength = strlen(etoken);
	elist = malloc(ylength + xlength + 2);
	elist = strdup(etoken);
	strcat(elist, "/");
	strcat(elist, command);
	strcat(elist, "\0");
	if (stat(elist, &info) == 0)
	{
	free(cmd2);
	return (elist);
	}
	else
	{
	free(elist);
	etoken = strtok(NULL, ":");
	}

	}
	free(cmd2);
	if (stat(command, &info) == 0)
	return (command);
	else
	return (NULL);
}
