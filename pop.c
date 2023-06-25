#include "monty.h"

/**
 * pop - Removes the top element of the stack.
 *
 * @stack: Double pointer to the stack
 * @line_number: Line number of the command in the source file
 *
 * Return: Nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (*stack == NULL)
        error_handler(stack, ERROR_POP, line_number, NULL, NULL);

    temp = *stack;
    *stack = (*stack)->next;
    free(temp);
}
