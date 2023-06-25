#include "monty.h"

/**
 * pint - Prints the value at the top of the stack, followed by a new line.
 *
 * @stack: Double pointer to the stack
 * @line_number: Line number of the command in the source file
 *
 * Return: Nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
    if (stack == NULL || *stack == NULL)
    {
        error_handler(stack, ERROR_PINT, line_number, NULL, NULL);
    }
    printf("%d\n", (*stack)->n);
}
