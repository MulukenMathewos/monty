#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;
	stack_t *top = *stack;

	if (!top || !(top->next))
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = top->n;
	top->n = top->next->n;
	top->next->n = temp;
}

/**
 * add - adds the top two elements of the stack
 * @stack: double pointer to the beginning of the stack
 * @line_number: line number of the opcode
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->n + (*stack)->next->n;
	temp = (*stack)->next;
	temp->n = sum;
	pop(stack, line_number);
}

/**
 * nop - doesn't do anything
 * @stack: double pointer to the beginning of the stack
 * @line_number: line number of the opcode
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
