#include "monty.h"

/**
 * main - Entry point for the Monty Language Interpreter.
 * @argc: Argument count.
 * @argv: Array of arguments.
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE.
 */
int main(int argc, char *argv[])
{
	FILE *script;
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	instruction_t opcode_func;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	script = fopen(argv[1], "r");
	if (!script)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((nread = getline(&line, &len, script)) != -1)
	{
		line_number++;
		opcode_func = get_opcode(line);
		if (opcode_func.f)
			opcode_func.f(&stack, line_number);
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s", line_number, line);
			exit(EXIT_FAILURE);
		}
	}

	free(line);
	fclose(script);
	free_stack(stack);
	exit(EXIT_SUCCESS);
}
