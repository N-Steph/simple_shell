#include "main.h"
#include <string.h>
#include <stdio.h>

/**
 * _getenv - gets an environment variable
 * @name: name of variable
 *
 * Return: pointer to variable value
 */
char *_getenv(const char *name)
{
	extern char **environ;
	int len_of_name, i, cmp_result;
	char *result_value;

	len_of_name = _strlen(name);
	i = 0;
	while (environ[i] != NULL)
	{
		cmp_result = strncmp(name, environ[i], len_of_name);
		if (cmp_result == 0)
		{
			break;
		}
		i++;
	}
	if (environ[i] == NULL)
		return NULL;
	result_value = environ[i];
	result_value += (len_of_name + 1);
	return (result_value);
}	
