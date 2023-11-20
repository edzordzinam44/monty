#include "monty.h"

/**
 * mul_nodes - Multiplies the top two elements of the stack.
 *
 * @stack: Pointer to the pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 *
 * Description: Multiplies the values of the top two elements of the stack.
 * If the stack contains less than two elements, it prints an error message.
 */

void mul_nodes(stack_t **stack, unsigned int line_number)
{
	int num;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "mul");

	(*stack) = (*stack)->next;
	num = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = num;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mod_nodes - Computes the remainder of the division of top two elements.
 *
 * @stack: Pointer to the pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 *
 * Description: Computes the remainder of the division of the top element by
 * the second element on the stack. If the stack contains less than two
 * elements or if the second element is 0, it prints an error message.
 */

void mod_nodes(stack_t **stack, unsigned int line_number)
{
	int num;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err(8, line_number, "mod");

	if ((*stack)->n == 0)
		more_err(9, line_number);
	(*stack) = (*stack)->next;
	num = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = num;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
