#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/* Global Variable */
stack_t *stack = NULL; /* Initialize the stack */

/* Function Prototypes */
void execute_instruction(char *opcode, char *arg, unsigned int line_number);
void free_stack(stack_t *stack);

/* Main Function */
int main(int argc, char *argv[])
{
    FILE *file;
    char line[1024];
    unsigned int line_number = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), file) != NULL)
    {
        char *opcode = strtok(line, " \t\n");
        char *arg = strtok(NULL, " \t\n");
        line_number++;

        if (opcode != NULL && opcode[0] != '#')
            execute_instruction(opcode, arg, line_number);
    }

    fclose(file);
    free_stack(stack);

    return 0;
}

/**
 * execute_instruction - Executes the opcode and its corresponding function
 * @opcode: the opcode to execute
 * @arg: the argument of the opcode
 * @line_number: the line number of the opcode in the file
 */
void execute_instruction(char *opcode, char *arg, unsigned int line_number)
{
    int i;
    instruction_t opcodes[] = {
        {"push", push},
        {"pall", pall},
        {NULL, NULL}};

    (void)arg;

    for (i = 0; opcodes[i].opcode != NULL; i++)
    {
        if (strcmp(opcode, opcodes[i].opcode) == 0)
        {
            if (opcodes[i].f != NULL)
            {
                opcodes[i].f(&stack, line_number);
                return;
            }
        }
    }

    fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
    exit(EXIT_FAILURE);
}

/**
 * free_stack - Frees the stack
 * @stack: pointer to the stack
 */
void free_stack(stack_t *stack)
{
    stack_t *temp;

    while (stack != NULL)
    {
        temp = stack;
        stack = stack->next;
        free(temp);
    }
}
