#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Struct for stack nodes */
typedef struct stack_s
{
    int n;
    struct stack_s *next;
} stack_t;

/* Global variables */
extern stack_t *stack;
extern unsigned int line_number;

/* Function prototypes */
void pint(void);
void execute_instruction(char *opcode, unsigned int line_number);

#endif /* MONTY_H */
