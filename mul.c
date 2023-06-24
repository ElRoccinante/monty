#include "monty.h"
#include <stdlib.h>

void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	*stack = (*stack)->next;
	(*stack)->n *= top->n;
	(*stack)->prev = NULL;
	free(top);
}
