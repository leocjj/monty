#include "monty.h"

/**
 * pall - pushes an element to the stack.
 * @number: value to be pushed
 * Return: void
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
