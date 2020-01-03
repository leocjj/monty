#include "monty.h"

/**
 * sub -  subtracts top element of the stack from the second top element
 * @head: top of the stack
 * @line_number: line number where a wrong command was found
 * Return: void
 */
void sub(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;
	int nnodes = 1; /*number of elements in stack*/
	(void) line_number;

	while (current->next != NULL)
	{
		current = current->next;
		nnodes++;
	}

	if (nnodes + 1 <= 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	current = *head; /*current equals to head to make substraction*/

	current->next->n = current->next->n - current->n; /*do the substraction*/

	free(current);
	*head = current->next;
	free(current);
}
