#include "monty.h"

stack_t *stack = NULL;
unsigned int line_number = 0;

void pint(void)
{
    if (stack == NULL)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", stack->n);
}

void execute_instruction(char *opcode, unsigned int line_number)
{
    if (strcmp(opcode, "pint") == 0)
    {
        pint();
        return;
    }

    /* Handle other opcodes... */
}
