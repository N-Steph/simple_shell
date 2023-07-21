#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
extern char **environ;

/**
 * compute_size - compute the size of array pointed by environ
 *
 * Return: Array size
 */
int compute_size(void)
{
	int i, count;

	count = 0;
	i = 0;
	while (environ[i] != NULL)
	{
		count++;
		i++;
	}
	return (count + 1);
}

/**
 * cp_env_var - copy environment variable to a another location
 * @new_env: pointer to an array of strings
 *
 * Return: address of byte after last environment variable
 */
char **cp_env_var(char **new_env)
{
	int i;

	if (new_env == NULL)
		return (NULL);
	i = 0;
	while (environ[i] != NULL)
	{
		*new_env = environ[i];
		new_env += 1;
		i++;
	}
	return (new_env);
}

/**
 * _setenv - Changes or adds environment vairable
 * @name: variable name
 * @value: variable's value
 * @overwrite: permission to overwrite variable's value
 *
 * Return: 0 (Success), -1 (failure)
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	char *result, *new_var;
	int num_var, len1, len2, i;
	char **new_env, **last_byte;

	if (name == NULL || value == NULL)
		return (-1);
	len1 = strlen(name);
	len2 = strlen(value);
	new_var = malloc(len1 + len2 + 2); /* NOT FREED */
	new_var = memcpy(new_var, name, len1);
	new_var = strcat(new_var, "=");
	new_var = strcat(new_var, value);
	result = _getenv(name);
	if (result == NULL)
	{
		num_var = compute_size();
		new_env = malloc(sizeof(char *) * (num_var + 1)); /* NOT FREED */
		if (new_env == NULL)
			return (-1);
		last_byte = cp_env_var(new_env);
		*last_byte = new_var;
		last_byte += 1;
		last_byte = NULL;
		environ = new_env;
	}
	else
	{
		if (overwrite != 0)
		{
			i = 0;
			while (environ[i] != NULL)
			{
				if (strncmp(environ[i], name, len1) == 0)
					break;
				i++;
			}
			environ[i] = new_var;
		}
	}
	return (0);
}
