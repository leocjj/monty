#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @head: top of the stack
 * @line_number: line number where a wrong command was found
 * Return: void
 */
void pint(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	stack_t *current = *head;

	printf("%d\n", current->n);
}
