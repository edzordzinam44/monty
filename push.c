#include "monty.h"

/**
 * push - adds an element to the stack
 * @stack: pointer to the top of the stack
 * @line_number: current line number in Monty file
 *
 * Description: Adds an element to the top of the stack
 * 	Creates a new node and sets it as the top.
 * 	If the stack doesn't exist, creates it.
 * Return: void
 */

void fn_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;

	if (validate_input() == 0)
	{
		free_stack(stack);
		hndlerr("usage: push integer\n", NULL, line_number);
	}
	new = malloc(sizeof(*new));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = line_number;
	new->prev = NULL;
	new->next = *stack;

	if (*stack)
	{
		(*stack)->prev = new;
	}

	*stack = new;
}
