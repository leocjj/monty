#include "monty.h"

/**
 * _pstr - prints the string starting at the top of the stack.
 * @stack: double pointer to header (top) of the stack.
 * @line_number: counter for line number of the file.
 *
 * Return: void.
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	int n;
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		printf("\n");
		return;
	}

	while (*temp != NULL)
	{
		n = (*stack)->n;
		if (n >= 1 && n <= 127) || n == 0)
			break;
		printf("%c", n);
	}

}
