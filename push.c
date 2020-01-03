#include "monty.h"

/**
 * push - pushes an element to the stack.
 * @number: value to be pushed
 * Return: void
 */

void push(int number)
{
	stack_s *new_node, *current;

	new_node = malloc(sizeof(stack_s));
	if (new_node = NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = number;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	new_node->next = current;
	current->prev = new_node;
	*head = new_node;

}
