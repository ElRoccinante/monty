#include "monty.h"

/**
 * check_digit - Checks if a string is a number
 * @param: Parameter to check
 * @line_count: Current line number
 * Return: The number as an integer
 */
int check_digit(char *param, unsigned int line_count)
{
	int num;

	num = atoi(param); // Convert the parameter to an integer
	if (num == 0 && strcmp(param, "0") != 0)
	{
		dprintf(2, "L%u: usage: push integer\n", line_count); // Error: Invalid parameter, expected integer
		free_all(); // Free allocated memory
		exit(EXIT_FAILURE); // Exit the program with failure status
	}
	return (num); // Return the number as an integer
}

/**
 * m_push - Pushes an element to the stack
 * @node: Pointer to the head of the stack
 * @line_count: Current line number
 * Return: Void function
 */
void m_push(stack_t **node, unsigned int line_count)
{
	int num;
	char *param;

	param = strtok(NULL, SEPARATORS); // Get the next token (parameter)

	if (!param)
	{
		dprintf(2, "L%u: usage: push integer\n", line_count); // Error: Missing parameter, expected integer
		free_all(); // Free allocated memory
		exit(EXIT_FAILURE); // Exit the program with failure status
	}
	num = check_digit(param, line_count); // Check if the parameter is a valid number
	if (!add_node(node, num))
	{
		dprintf(2, "Error: malloc failed\n"); // Error: Memory allocation failed
		free_all(); // Free allocated memory
		exit(EXIT_FAILURE); // Exit the program with failure status
	}
}
