#include "main.h"
/**
* execution - this function is used to execute commands
* @argv: the arguments
* @envp: environment variables
*/

void execution(char **argv, char **envp)
{
	char *root = NULL;
	int check;

	root = environment(argv[0]);
	check = execve(root, argv, envp);
	if (check == -1)
	perror("ERROR");
}
