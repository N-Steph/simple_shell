#include <stdio.h>
#include <string.h>

/**
 * print_dir_path - prints each directory in variable PATH
 *
 * Return: nothing
 */
void print_dir_path(void)
{
	char *value, *token;

	value = _getenv("PATH");
	token = strtok(value, ":");
	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, ":");
	}
}
