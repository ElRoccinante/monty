#include "monty.h"

void rotr(stack_t **stack, unsigned int line_number)
{
    /* Rotate the stack to the bottom */
    if (*stack && (*stack)->next)
    {
        stack_t *last = *stack;

        while (last->next)
            last = last->next;

        last->next = *stack;
        (*stack)->prev = last;
        *stack = last;
        (*stack)->prev->next = NULL;
        (*stack)->prev = NULL;
    }

    (void)line_number;
}
