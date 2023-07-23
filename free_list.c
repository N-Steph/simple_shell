#include "main.h"

/**
 * free_list - frees a list_t list
 * @head: pointer to head node of list_t list
 *
 * Return: nothing
 */
void free_list(struct dir_node *head)
{
	struct dir_node *ptr_temp;

	if (head == 0)
		return;
	while (head->next != 0)
	{
		ptr_temp = head;
		head = head->next;
		/*free(ptr_temp->dir);*/
		free(ptr_temp);
	}
	/*free(ptr_temp->dir);*/
	free(head);
}
