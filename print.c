#include "monty.h"

/**
 * print - Prints the elements of a double linked list
 * @h: Pointer to the head of the list
 * Return: Number of nodes in the list
 */
size_t print(stack_t *h)
{
	size_t i = 0;

	while (h)
	{
		printf("%d\n", h->n); // Print the value of the current node
		h = h->next; // Move to the next node
		i++; // Increment the node count
	}
	return (i); // Return the total number of nodes
}
