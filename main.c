#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

stack_t *stack = NULL;

void execute_instruction(char *opcode, char *arg, unsigned int line_number);

/* Opcode Functions */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number); /* New function for pstr */

/**
 * opcodes - Array of opcode and corresponding function pointer
 */
instruction_t opcodes[] = {
    {"push", push},
    {"pall", pall},
    {"pint", pint},
    {"pchar", pchar},
    {"pstr", pstr}, /* Add pstr opcode and function pointer */
    {NULL, NULL}
};

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[])
{
    FILE *script;
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    unsigned int line_number = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    script = fopen(argv[1], "r");
    if (script == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((nread = getline(&line, &len, script)) != -1)
    {
        line_number++;
        opcode = strtok(line, " \t\n");
        if (opcode == NULL || opcode[0] == '#')
            continue;
        arg = strtok(NULL, " \t\n");
        execute_instruction(opcode, arg, line_number);
    }

    free(line);
    fclose(script);
    free_stack(stack);

    return 0;
}

/**
 * execute_instruction - Executes the given opcode instruction
 * @opcode: The opcode
 * @arg: The argument (if any)
 * @line_number: The line number in the script file
 */
void execute_instruction(char *opcode, char *arg, unsigned int line_number)
{
    int i = 0;

    while (opcodes[i].opcode != NULL)
    {
        if (strcmp(opcode, opcodes[i].opcode) == 0)
        {
            opcodes[i].f(&stack, line_number, arg);
            return;
        }
        i++;
    }

    fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
    exit(EXIT_FAILURE);
}

/**
 * push - Pushes an element to the stack
 * @stack: Double pointer to the stack
 * @line_number: The line number in the script file
 * @arg: The argument to push
 */
void push(stack_t **stack, unsigned int line_number, char *arg)
{
    int value;

    if (arg == NULL || !is_number(arg))
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    value = atoi(arg);
    add_node(stack, value);
}

/**
 * pall - Prints all the elements in the stack
 * @stack: Double pointer to the stack
 * @line_number: The line number in the script file
 * @arg: Unused argument
 */
void pall(stack_t **stack, unsigned int line_number, char *arg)
{
    stack_t *current = *stack;

    (void)arg;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

/**
 * pint - Prints the value at the top of the stack
 * @stack: Double pointer to the stack
 * @line_number: The line number in the script file
 * @arg: Unused argument
 */
void pint(stack_t **stack, unsigned int line_number, char *arg)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}

/**
 * pchar - Prints the char at the top of the stack
 * @stack: Double pointer to the stack
 * @line_number: The line number in the script file
 * @arg: Unused argument
 */
void pchar(stack_t **stack, unsigned int line_number, char *arg)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n < 0 || (*stack)->n > 127)
    {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%c\n", (*stack)->n);
}

/**
 * pstr - Prints the string starting at the top of the stack
 * @stack: Double pointer to the stack
 * @line_number: The line number in the script file
 * @arg: Unused argument
 */
void pstr(stack_t **stack, unsigned int line_number, char *arg)
{
    stack_t *current = *stack;

    (void)arg;

    while (current != NULL && current->n != 0 && (current->n > 0 && current->n <= 127))
    {
        printf("%c", current->n);
        current = current->next;
    }

    printf("\n");
}

/**
 * is_number - Checks if a string is a valid number
 * @str: The string to check
 *
 * Return: 1 if the string is a number, 0 otherwise
 */
int is_number(char *str)
{
    if (str == NULL || *str == '\0')
        return 0;

    if (*str == '-')
        str++;

    while (*str != '\0')
    {
        if (*str < '0' || *str > '9')
            return 0;
        str++;
    }

    return 1;
}

/**
 * add_node - Adds a new node at the beginning of a stack_t list
 * @stack: Double pointer to the head of the stack
 * @n: The value to add to the new node
 *
 * Return: The address of the new element, or NULL if it failed
 */
stack_t *add_node(stack_t **stack, int n)
{
    stack_t *new_node;

    if (stack == NULL)
        return NULL;

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack != NULL)
        (*stack)->prev = new_node;

    *stack = new_node;

    return new_node;
}

/**
 * free_stack - Frees a stack_t list
 * @stack: The stack to free
 */
void free_stack(stack_t *stack)
{
    stack_t *current;

    while (stack != NULL)
    {
        current = stack;
        stack = stack->next;
        free(current);
    }
}
