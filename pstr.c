#include "monty.h"

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;

	if (stack && *stack)
	{
		current = *stack;
		while (current != NULL && current->n != 0)
		{
			if (current->n < 0 || current->n > 127)
				break;
			printf("%c", current->n);
			current = current->next;
		}
	}
	printf("\n");
}
