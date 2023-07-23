#include "main.h"

/**
 * _printenv - prints environment variable
 *
 * Return: nothing
 */
void _printenv(void)
{
	int i;

	i = 0;
	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
