#include "monty.h"

/**
 * print_rev - Prints a double linked list in reverse order
 * @h: Pointer to the head of the list
 * Return: Number of nodes in the list
 */
size_t print_rev(stack_t *h)
{
	size_t i = 0;

	while (h->next)
	{
		h = h->next; // Move to the last node
	}
	while (h)
	{
		h = h->prev; // Move to the previous node
		i++; // Increment the node count
	}
	return (i); // Return the total number of nodes
}
