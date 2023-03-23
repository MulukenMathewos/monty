#include "monty.h"

/**
 * get_opcode - gets the function pointer associated with the given opcode.
 * @line: The line being processed.
 *
 * Return: Function pointer of the opcode function.
 */
instruction_t get_opcode(char *line)
{
	int i;
	char *opcode;
	instruction_t opcode_func;

	opcode_func.f = NULL;
	opcode = strtok(line, " \n\t");

	if (!opcode || opcode[0] == '#')
		return (opcode_func);

	for (i = 0; opcode_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode_list[i].opcode, opcode) == 0)
		{
			opcode_func = opcode_list[i];
			break;
		}
	}
	return (opcode_func);
}

/**
 * free_stack - frees a stack.
 * @stack: pointer to head of stack
 *
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}
