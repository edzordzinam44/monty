#include "monty.h"

/**
 * main - Monty code interpreter
 * @agrc: number of arguments
 * @argv: file location
 *
 * Return: 0 on success
 */

int main(int argc, char **argv)
{
	unsigned int line_number = 0;
	char *line = NULL;
	stack_t *stack = NULL;
	size_t len = 0;
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		hndlerr("Error: Can't open file\n", argv[1], line_number);
	}

	/* Process the file opened successfully */
	for (line_number = -1, getline(&line, &len, file) != -1, line_number++)
	{
		interpret(&stack, line, line_number);
	}

	free(line); /* Free aallocated memory for line */
	line = NULL; /* Sets pointer to null */

	if (stack)
	{
		free_stack(&stack); /* Free allocated memory foor stack */
	}

	fclose(file);
	exit(EXIT_SUCCESS); /* Exit with success status */
}
