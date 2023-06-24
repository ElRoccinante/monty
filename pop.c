#include "monty.h"

/**
 * m_pop - Deletes the element at the top of the stack
 * @head: Double pointer to the head of the double linked list
 * @line_count: Current line of the Monty file
 * Return: Void
 */
void m_pop(stack_t **head, unsigned int line_count)
{
	stack_t *temp;

	if (!(*head) || !head)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", line_count); // Error: Trying to pop from an empty stack
		free_all(); // Free allocated memory
		exit(EXIT_FAILURE); // Exit the program with failure status
	}
	temp = *head; // Store the current top node
	if (temp->next)
	{
		temp->next->prev = NULL; // Update the prev pointer of the next node
		*head = temp->next; // Move the head pointer to the next node
	}
	else
		*head = NULL; // If there is only one node, set the head to NULL
	free(temp); // Free the memory of the previous top node
}
