#include "monty.h"

/**
 * _pall - pushes an element to the stack.
 * @head: double pointer to header (top) of the stack.
 * @line_number: counter for line number of the file.
 *
 * Return: void.
 */
void _pall(stack_t **head, unsigned int line_number)
{
	stack_t *current;

	(void) line_number;
	current = *head;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
