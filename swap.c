#include "monty.h"

/**
 * push - pushes an element to the stack.
 * @number: value to be pushed
 * Return: void
 */
void swap(stack_t **head, unsigned int line_number)
{
	stack_t *new_node = NULL;
	size_t len = 0, i = 0;

	if (opcode[1] == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	len = strlen(opcode[1]);
	for (i = 0; i < len; i++)
		if (!isdigit(opcode[1][i]))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}

	if (head == NULL)
		exit(EXIT_FAILURE);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(opcode[1]);
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
