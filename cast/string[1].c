#include "monty.h"

/**
 * print_char - Prints the ASCII value of the top node.
 *
 * @stack: Pointer to the pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 *
 * Description: Retrieves the integer value from the top node of the stack
 * and prints the corresponding ASCII character. If the stack is empty,
 * it prints an error message.
 */
void print_char(stack_t **stack, unsigned int line_number)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		string_err(11, line_number);

	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
		string_err(10, line_number);
	printf("%c\n", ascii);
}

/**
 * print_str - Prints a string from the stack.
 *
 * @stack: Pointer to the pointer pointing to the top node of the stack.
 * @lne: Integer representing the line number of the opcode.
 *
 * Description: Retrieves and prints a string from the stack, starting from
 * the top node. It stops printing when it encounters a 0 or an empty stack.
 */
void print_str(stack_t **stack, __attribute__((unused))unsigned int lne)
{
	int ascii;
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	temp = *stack;
	while (temp != NULL)
	{
		ascii = temp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		temp = temp->next;
	}
	printf("\n");
}
/**
 * rotl - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lne: Interger representing the line number of of the opcode.
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int lne)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
 * rotr - Rotates the last node of the stack to the top.
 *
 * @stack: Pointer to the pointer pointing to the top node of the stack.
 * @lne: Integer representing the line number of the opcode.
 *
 * Description: Moves the last element of the stack to the top. The last node
 * becomes the new top node, and the rest of the nodes move down one position.
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int lne)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*stack)->prev = temp;
	(*stack) = temp;
}
