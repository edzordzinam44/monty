#include "monty.h"

/**
 * add_to_stack - Adds a node to the stack.
 *
 * @new_node: Pointer to the new node.
 * @ln: Integer representing the line number of the opcode.
 *
 * Description: Inserts a new node at the top of the stack.
 * Takes a pointer to the new node and the current line number
 * of the opcode.
 */
void add_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	temp = head;
	head = *new_node;
	head->next = temp;
	temp->prev = head;
}

/**
 * print_stack - Prints all elements of the stack.
 *
 * @stack: Pointer to the pointer pointing to the top node of the stack.
 * @line_number: Line number of the opcode.
 *
 * Description: Prints all elements present in the stack starting from the
 * top node. The stack remains unchanged after this operation.
 */

void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pop_top - Removes the top node from the stack.
 *
 * @stack: Pointer to the pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 *
 * Description: Removes the top node from the stack. If the stack is empty,
 * it prints an error message.
 */
void pop_top(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
		more_err(7, line_number);

	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * print_top - Prints the value of the top node of the stack.
 *
 * @stack: Pointer to the pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 *
 * Description: Prints the value stored in the top node of the stack.
 * If the stack is empty, it prints an error message.
 */
void print_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, line_number);
	printf("%d\n", (*stack)->n);
}
