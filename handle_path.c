#include "main.h"

/**
 * handle_path - handle the path of command line argument
 * This function is going to check for the existence of
 * a command
 *
 * @args: array of arguments
 *
 * Return: 0 (success), -1 (failure), 1(Success, full path passed)
 */
int handle_path(char **args)
{
	struct stat statbuf;
	struct dir_node *node, *head;
	char *mem;

	if (args == NULL)
		return (-1);
	if (stat(args[0], &statbuf) != 0)
	{
		/* Put this code in a function */
		node = linked_list_dir_path();
		head = node;
		while (node->next != NULL)
		{
			mem = malloc(sizeof(char) * (strlen(node->dir) + strlen(args[0]) + 2));
			if (mem == NULL)
				return (-1);
			mem = memset(mem, 'x', (strlen(node->dir) + strlen(args[0]) + 2));
			mem = strcpy(mem, node->dir);
			/*mem = memcpy(mem, node->dir, strlen(node->dir));*/
			mem = strcat(mem, "/");
			mem = strcat(mem, args[0]);
			if (stat(mem, &statbuf) == 0)
			{
				free(head->dir);
				free_list(head);
				args[0] = mem;
				return (0);
			}
			free(mem);
			node = node->next;
		}
		free(head->dir);
		free_list(head);
	}
	else
	{
		return (1);
	}
	return (-1);
}
