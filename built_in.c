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
	char *cmd_built_in[2] = {"exit", "env", "setenv", "unsetenv"};
	int status;

	if (strcmp(args[0], cmd_built_in[0]) == 0)
	{
		if (args[1] == NULL || strcmp(args[1], "0") == 0)
		{
			free(lineptr);
			exit(0);
		}
		else
		{
			status = atoi(args[1]);
			if (status == 0)
			{
				printf("hsh : 1 : Illegal number : %s\n", args[1]);
				free(lineptr);
				exit(2);
			}
			free(lineptr);
			exit(status);
		}
	}
	else if (strcmp(args[0], cmd_built_in[1]) == 0)
	{
		_printenv();
	}
}
