#include "monty.h"

/**
 * m_pchar - Prints the top stack number as ASCII character
 * @node: Pointer to the head of the stack
 * @line_count: Current line number
 * Return: Void function
 */
void m_pchar(stack_t **node, unsigned int line_count)
{
	int num = 0;

	if (!*node || !node)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", line_count); // Error: Stack is empty
		free_all(); // Free allocated memory
		exit(EXIT_FAILURE); // Exit the program with failure status
	}
	num = (*node)->n; // Get the value of the top node
	if ((num < 33) || (num > 127))
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", line_count); // Error: Value is out of range
		free_all(); // Free allocated memory
		exit(EXIT_FAILURE); // Exit the program with failure status
	}
	putchar(num); // Print the ASCII character corresponding to the value
	putchar('\n'); // Print a new line character
}
