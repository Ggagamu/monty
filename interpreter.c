#include "monty.h"
/**
 * main - Entry point.
 * @argc: Arguments counter.
 * @argv: Arguments vector.
 *
 * Return: EXIT_SUCCESS (Success), EXIT_FAILURE (failed).
 */

int main(int argc, char *argv[])
{
	FILE *file = NULL;
	int result = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	result = process(file, &stack);
	fclose(file);
	free_stack(stack);
	return (result);
}
