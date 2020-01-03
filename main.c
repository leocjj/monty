#include "monty.h"

/**
 * valid_opcode - reads opcode and verifies if is valid.
 * @opcode: string with opcode to validate.
 *
 * Return: 1 if there is a valid opcode or 0 if not.
 */
int valid_opcode(char *opcode)
{
	int i = 0;
	char *strs[] = {"push", "pall", "pint", "pop", "swap", "add", "nop",
			NULL};

	for (i = 0; strs[i] != NULL; i++)
		if (strcmp(opcode, strs[i]) == 0)
			return (1);
	return (0);
}

/**
 * token_opcode - reads line and tokenize for opcode an argumen if any.
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
	char *line = NULL, **opcode = NULL;
	size_t len = 0;
	ssize_t nread = 0;
	int line_number = 1;

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
		if (valid_opcode(opcode[0]))
		{
			printf("<%s><%s>\n", opcode[0], opcode[1]);
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode[0]);
			exit(EXIT_FAILURE);
		}
		line_number++;
	}

	free(line);
	free(opcode);
	fclose(stream);
	exit(EXIT_SUCCESS);
}
