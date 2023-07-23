#include "main.h"

/**
 * linked_list_dir_path - creates a linked list of PATH directories
 *
 * Return: pointer to first node of linked list
 */
struct dir_node *linked_list_dir_path(void)
{
	/* note that this linked list is not freed */
	char *value, *token, *new_value;
	struct dir_node *head, *prev_node, *next_node;

	value = _getenv("PATH");
	new_value = malloc(sizeof(char) * (strlen(value) + 1));
	if (new_value == NULL)
		return (NULL);
	new_value = strcpy(new_value, value);
	token = strtok(new_value, ":");
	head = NULL;
	while (token != NULL)
	{
		next_node = malloc(sizeof(struct dir_node) * 1);
		if (next_node == NULL)
			return (NULL);
		if (head == NULL)
		{
			head = next_node;
			prev_node = next_node;
			next_node->dir = token;
			next_node->next = NULL;
		}
		else
		{
			next_node->dir = token;
			next_node->next = NULL;
			prev_node->next = next_node;
			prev_node = next_node;
		}
		token = strtok(NULL, ":");
	}
	return (head);
}
