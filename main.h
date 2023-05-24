#ifndef MAIN
#define MAIN
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
char *environment(char *command);
void execution(char **argv, char **envp);
int leave(char **argv);
#endif
