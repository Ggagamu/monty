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
		{"push", pushInt},
		{"pall", prntall},
		{"pint", prntInt},
		{"pop", PoP},
		{"swap", SwaP},
		{"add", plus},
		{"nop", nope},
		{"sub", minus},
		{"div", by},
		{"mul", multiply},
		{"mod", modulo},
		{"pchar", prntchar},
		{"pstr", prntstr},
		{"rotl", m_rotl},
		{"rotr", m_rotr},
		{"stack", m_stack},
		{"queue", m_queue},
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
