#include "monty.h"

/**
 * executeMontyInstruction -  Executes the Monty instruction associated with the opcode.
 * @opcode: Opcode.
 * @stack: dPointer to the stack.
 * @line_number: Line number in sript.
 */

void executeMontyInstruction(char *opcode, stack_t **stack, unsigned int line_number)
{
	int i;

	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divi},
		{"mul", mult},
		{"mod", modu},
		{"pchar", pchar},
		{"pstr", pstr},
		{NULL, NULL}
	};

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
