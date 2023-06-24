#include "monty.h"

/**
 * rotl - Rotates the first element of the stack to the top
 * @stack: Pointer to the stack head
 * @line_count: Line count (unused)
 *
 * Return: Void
 */
void rotl(stack_t **stack, unsigned int line_count)
{
	stack_t *left;
	stack_t *right;

	(void)line_count; // Unused line count parameter

	if (!stack || !*stack || !(*stack)->next)
		return; // If the stack is empty or has only one element, no rotation is needed

	left = right = *stack;

	while (right->next) // Move the right pointer to the last node
		right = right->next;

	right->next = left; // Create a circular infinite linked list loop
	left->prev = right;

	*stack = left->next; // Move the stack head to the next element
	(*stack)->prev->next = NULL; // Cut the link between the previous top and the new top
	(*stack)->prev = NULL; // Update the previous pointer of the new top
}
