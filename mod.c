#include "monty.h"
#include <stdlib.h>

void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	if (top->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->next;
	(*stack)->n %= top->n;
	(*stack)->prev = NULL;
	free(top);
}
