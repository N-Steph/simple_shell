#include "main.h"

/**
 * _unsetenv - delete an environment variable
 * @name: environment variable to delete
 *
 * Return: 0 (Success), -1 (failure)
 */
int _unsetenv(const char *name)
{
	char *value;
	int i;

	if (name == NULL)
		return (-1);
	value = _getenv(name);
	if (value != NULL)
	{
		i = 0;
		while (environ[i] != NULL)
		{
			if (strncmp(environ[i], name, strlen(name)) == 0)
				break;
			i++;
		}
		while (environ[i] != NULL)
		{
			environ[i] = environ[i + 1];
			i++;
		}
	}
	return (0);
}
