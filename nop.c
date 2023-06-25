#include "monty.h"

/**
 * nop - Doesn't do anything
 *
 * @stack: Double pointer to the stack
 * @line_number: Line number of the command in the source file
 *
 * Return: Nothing
 */
void nop(stack_t **stack, unsigned int line_number)
{
    (void)line_number;
    (void)stack;
}
