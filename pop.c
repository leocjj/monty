#include "monty.h"

/**
 * pop - removes the top elements of the stack.
 * @head: top of the stack
 * @line_number: line number where a wrong command was found
 * Return: void
 */
void pop(stack_t **head, unsigned int line_number)
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
