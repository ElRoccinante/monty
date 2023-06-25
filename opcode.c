#include "monty.h"

/**
  * select_op - Selects and returns the corresponding function pointer
  *		based on the given opcode.
  * @s: Pointer to the op string
  *
  * Return: Pointer to the function corresponding to the opcode,
  *		or NULL if no match is found.
  */

void (*select_op(char *s))(stack_t **, unsigned int)
{
	int i;
	instruction_t ops[] = {
		{ "push", push },
		{ "pall", pall }
	};

	for (i = 0; ops[i].opcode; i++)
	{
		if (strcmp(s, ops[i].opcode) == 0)
			return (ops[i].f);
	}

	return (NULL);
}
