#include "monty.h"

/**
 * m_pstr - Prints the stack as ASCII code
 * @node: Pointer to the head of the stack
 * @line_count: Current line number (unused)
 * Return: Void function
 */
void m_pstr(stack_t **node, __attribute__((unused)) unsigned int line_count)
{
	stack_t *temp = *node;

	while (temp && (temp->n != 0) && ((temp->n) > 32) && ((temp->n) < 128))
	{
		printf("%c", temp->n); // Print the ASCII character corresponding to the value
		temp = temp->next; // Move to the next node
	}
	putchar('\n'); // Print a new line character
}
