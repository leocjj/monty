#include "monty.h"

/**
 * _pint - prints the value at the top of the stack
 * @head: double pointer to header (top) of the stack.
 * @line_number: counter for line number of the file.
 *
 * Return: void.
 */
void _pint(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", current->n);
}
