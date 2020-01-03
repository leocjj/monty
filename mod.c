#include "monty.h"

/**
 * mod -  get the module of the second top element of the stack and top element
 * @head: top of the stack
 * @line_number: line number where a wrong command was found
 * Return: void
 */
void mod(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;
	int nnodes = 1; /*number of elements in stack*/

	while (current->next != NULL)
	{
		current = current->next;
		nnodes++;
	}

	if (nnodes + 1 <= 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	current = *head; /*current equals to head to make division*/

	if (current->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	current->next->n = current->next->n % current->n; /*do the mod*/

	free(current);
	*head = current->next;
	free(current);
}
