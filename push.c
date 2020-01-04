#include "monty.h"

/**
 * _push -  pushes an element to the stack.
 * @head: double pointer to header (top) of the stack.
 * @line_number: counter for line number of the file.
 *
 * Return: void.
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = NULL;
	size_t len = 0, i = 0;
	char arg[128] = "";
	char *argument = arg;

	argument = strtok(NULL, " \t\r\n\v\f");

	if (argument == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
		free_stack_t(*stack);
		exit(EXIT_FAILURE);
	}

	len = strlen(argument);
	for (i = 0; i < len; i++)
		if (!isdigit(argument[i]))
		{
			dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
			free_stack_t(*stack);
			exit(EXIT_FAILURE);
		}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free_stack_t(*stack);
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(argument);
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
