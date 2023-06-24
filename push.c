#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	int value;

	if (!stack)
	{
		fprintf(stderr, "L%d: stack is NULL\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (!stack || !stack[1])
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi((const char *)stack[1]);

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}
