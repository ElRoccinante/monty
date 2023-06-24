#include <stdio.h>
#include "monty.h"

/**
 * pchar - Prints the character at the top of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number of the current opcode
 */
void pchar(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    int value = (*stack)->n;

    if (value < 0 || value > 127)
    {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%c\n", value);
}
