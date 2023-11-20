#include "monty.h"

/**
 * main - Entry point for the program.
 *
 * @argc: Number of command-line arguments.
 * @argv: Array of pointers to command-line arguments.
 * Return: Always returns 0 to indicate successful execution.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1]);
	free_nodes();
	return (0);
}

/**
 * create_node - Creates a new node.
 *
 * @n: Number to be stored in the node.
 * Return: Pointer to a newly created node on success. Otherwise returns NULL
 *
 * Description: Allocates memory for a new node and stores the given number
 * inside it. Returns a pointer to the created node if successful; otherwise,
 * returns NULL if memory allocation fails.
 */
stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		err(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * free_nodes - Frees all nodes in the stack.
 *
 * Description: Frees all memory allocated for nodes in the stack.
 * Iterates through the stack and deallocates memory for each node.
 */
void free_nodes(void)
{
	stack_t *temp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

/**
 * add_too_queue - Adds a node to the queue.
 * @new_node: Pointer to the new node.
 * @lne: line number of the opcode.
 */

void add_too_queue(stack_t **new_node, __attribute__((unused))unsigned int lne)
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
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *new_node;
	(*new_node)->prev = temp;
}
