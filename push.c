#include "monty.h"

/**
 * push - pushes an element to the stack.
 * @number: value to be pushed
 * Return: void
 */

void push(stack_t **head, unsigned int line_number)
{
	stack_s *new_node = NULL;

	(void) line_number;

	if (head == NULL)
		exit(EXIT_FAILURE);

	new_node = malloc(sizeof(stack_s));
	if (new_node = NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = number;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (*head == NULL)
		*head = new_node;
	else
	{
		new_node->next = *head;
		(*head)->prev = new_node;
		*head = new_node;
	}
}
