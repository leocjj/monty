#include "monty.h"

/**
 * _pop - removes the top elements of the stack.
 * @head: double pointer to header (top) of the stack.
 * @line_number: counter for line number of the file.
 *
 * Return: void.
 */
void _pop(stack_t **head, unsigned int line_number)
{
	stack_t *current;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	current = *head;
	*head = current->next;
	free(current);
}
