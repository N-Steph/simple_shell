#include "main.h"

/**
 * handle_args - Handle command lines arguments
 * This function takes in all the arguments read by
 * getline function and place them in an array
 *
 * @lineptr: pointer to the buffer containing arguments
 * @args: array of arguments
 *
 * Return: Nothing
 */
void handle_args(char **lineptr, char **args)
{
	char *token;

	token = strtok(*lineptr, " \n");
	while (token != NULL)
	{
		*args = token;
		args++;
		token = strtok(NULL, " \n");
	}
	*args = NULL;
}
