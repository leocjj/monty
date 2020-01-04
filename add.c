#include "monty.h"

/**
 * _add - adds the top two elements of the stack.
 * @head: double pointer to header (top) of the stack.
 * @line_number: counter for line number of the file.
 *
 * Return: void.
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = NULL;
	size_t len = 0, i = 0;

	if (opcode[1] == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	len = strlen(opcode[1]);
	for (i = 0; i < len; i++)
		if (!isdigit(opcode[1][i]))
		{
			dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}

	if (stack == NULL)
		exit(EXIT_FAILURE);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(opcode[1]);
	new_node->prev = NULL;
	new_node->next = NULL;

	if (*stack == NULL)
		*stack = new_node;
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
		*stack = new_node;
	}
}
