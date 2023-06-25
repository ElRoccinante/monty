#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack.
 *
 * @stack: Double pointer to the stack
 * @line_number: Line number of the command in the source file
 *
 * Return: Nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
    stack_t *top, *second;

    if (!(*stack) || !(*stack)->next)
        error_handler(stack, ERROR_SWAP, line_number, NULL, NULL);

    top = *stack;
    second = (*stack)->next;

    top->next = second->next;
    second->next = top;

    *stack = second;
}
