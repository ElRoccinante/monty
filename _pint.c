#include "monty.h"

/**
 * _push - Pushes an element to the stack
 * @stack: Pointer to the head of the stack
 * @line_number: Line number
 *
 * Description: This function pushes an integer element onto the stack.
 *
 * Return: void
 */
void _push(stack_t **stack, unsigned int line_number)
{
    int val;
    char *arg = strtok(NULL, " \n\t");
    stack_t *new_element;

    if (arg == NULL || (!isdigit(*arg) && *arg != '-'))
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    val = atoi(arg);

    new_element = malloc(sizeof(stack_t));

    if (new_element == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_element->n = val;
    new_element->prev = NULL;
    new_element->next = *stack;

    if (*stack != NULL)
        (*stack)->prev = new_element;

    *stack = new_element;
}
