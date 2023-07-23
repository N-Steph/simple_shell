#include "main.h"

/**
 * built_in - check for shell built_in command
 *
 * @args: array of arguments
 * @lineptr: pointer to buffer of argument read by getline()
 *
 * Return: nothing
 */
void built_in(char **args, char *lineptr)
{
	char *cmd_built_in[2] = {"exit", "env"};

	if (strcmp(args[0], cmd_built_in[0]) == 0)
	{
		free(lineptr);
		printf("UUUUUUUUU\n");
		exit(0);
	}
	else if (strcmp(args[0], cmd_built_in[0]) == 0)
	{
		_printenv();
	}
}
