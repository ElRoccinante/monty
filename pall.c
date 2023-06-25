#include "monty.h"

/**
 * pall - Prints all the values on the stack, starting from the top of the stack.
 *
 * @stack: Double pointer to the stack
 * @line_number: Line number of the command in the source file
 *
 * Return: Nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *curr = NULL;
    (void)line_number;

    if (!(*stack))
        return;

    curr = *stack;
    while (curr)
    {
        printf("%d\n", curr->n);
        curr = curr->next;
    }
}
