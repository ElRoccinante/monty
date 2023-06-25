#include "monty.h"

/**
  * free_stack - Frees nodes in a doubly linked stack list
  * @head: Double pointer to the stack
  * Return: Nothing
  */

void free_stack(stack_t **head)
{
	stack_t *curr = NULL;

	if (!head)
		return;

	curr = *head;
	while (curr)
	{
		*head = (*head)->next;
		free(curr);
		curr = *head;
	}
}
