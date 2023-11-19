#include "monty.h"
/**
 * executeMontyCommands - Executes monty commands
 * @file: Pointer to the FILE structure
 * @stack: dPointer 
 * Return: EXIT_SUCCESS (Success) or EXIT_FAILURE (failed).
 */
int executeMontyCommands(FILE *file, stack_t **stack)
{
	char *line = NULL;
	size_t n = 0;
	unsigned int line_number = 0;
	ssize_t read_line;
	size_t index;

	while ((read_line = getline(&line, &n, file)) != -1)
	{
		line_number++;
		index = 0;
		while (line[index] != '\0' && isspace(line[index]))
			index++;
		if (line[index] == '#')
			continue;
		if (read_line > 0 && line[read_line - 1] == '\n')
			line[read_line - 1] = '\0';
		token = splitString(line);
		if (token[0] != NULL)
		{
			executeMontyInstruction(token[0], stack, line_number);
		}
		free_token(token);
	}
	free(line);
	if (feof(file))
	{
		return (EXIT_SUCCESS);
	}
	else
	{
		return (EXIT_FAILURE);

	}
}
