#include "monty.h"

char **opcode = NULL;

/**
 * main - Entry point
 * @argc: number of arguments passed as parameter to main program.
 * @argv: array of strings with the parameters passed to main program
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on any failure.
 */
int main(int argc, char *argv[])
{
	FILE *stream = NULL;
	char *line = NULL;
	size_t len = 0;
	ssize_t nread = 0;
	unsigned int line_number = 1;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	stream = fopen(argv[1], "r");
	if (stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((nread = getline(&line, &len, stream)) != -1)
	{
		opcode = token_opcode(line);
		printf("<%s><%s>\n", opcode[0], opcode[1]);
		(*get_opcode(&stack, line_number))(&stack, line_number);
		line_number++;
	}

	free(line);
	free(opcode);
	fclose(stream);
	exit(EXIT_SUCCESS);
}

/**
 * get_opcode - reads opcode and verifies if is valid.
 * @stack: double pointer to header (top) of the stack.
 * @line_number: counter for line number of the file.
 *
 * Return: void.
 */
void (*get_opcode(stack_t **stack, unsigned int line_number))\
(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	(void) stack;
	instruction_t opcode_func[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	while (opcode_func[i].opcode)
	{
		if (strcmp(opcode_func[i].opcode, opcode[0]) == 0)
			return (opcode_func[i].f);
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode[0]);
	exit(EXIT_FAILURE);
}

/**
 * token_opcode - reads line and get tokens for opcode and argument if any.
 * @line: pointer to line with opcodes.
 *
 * Return: pointer to array of pointers with opcode and arguments if any found.
 */
char **token_opcode(char *line)
{
	const char s[7] = " \t\r\n\v\f";
	char **result;

	result = malloc(2 * sizeof(char *));
	if (result == NULL)
		return (NULL);

	/**
	 * Takes first token found as opcode and store it in result[0].
	 * Takes second token (if any) as argument and store it in result[1].
	 */
	result[0] = strtok(line, s);
	result[1] = strtok(NULL, s);
	return (result);
}
