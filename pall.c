#include "monty.h"

/**
 * pall - pushes an element to the stack.
 * @head: double pointer to header (top) of the stack.
 * @line_number: counter for line number of the file.
 *
 * Return: void.
 */
void pall(stack_t **head, unsigned int line_number)
{
	(void) line_number;

	stack_t *current = *head;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
