#include "monty.h"

/**
 * rotr - Rotates the last node of a stack_t stack to the bottom
 * @stack: Pointer to the stack head
 * @line_count: Line count (unused)
 *
 * Return: Void
 */
void rotr(stack_t **stack, unsigned int line_count)
{
	stack_t *bottom;
	stack_t *prev;

	(void)line_count; // Unused line count parameter

	if (!stack || !*stack || !(*stack)->next)
		return; // If the stack is empty or has only one element, no rotation is needed

	bottom = *stack;

	while (bottom->next)
		bottom = bottom->next; // Move to the last node

	prev = bottom->prev; // Store the previous node
	bottom->next = *stack; // Make the last node the new head
	bottom->prev = NULL; // Update the previous pointer of the new bottom
	prev->next = NULL; // Cut the link between the previous bottom and the new bottom
	(*stack)->prev = bottom; // Update the previous pointer of the new head
	*stack = bottom; // Set the new head as the bottom node
}
