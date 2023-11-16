#include "monty.h"

/* Global */
StackQueue_t StackQueue = {200};

/* Local */
void pint_m(stack_t **stack, unsigned int line_number);

/**
 * main - main function.
 * @argc: Arguments counter.
 * @argv: Arguments vector. 
 * Return: 0; success and 1; failure.
 */

int main(int argc, char *argv[])
{
	char buffer[100],
	FILE *bytecodes;
	unsigned int index = 0;
	stack_t *unstable_stack = NULL;
	size_t index_scnd = 0;

	instruction_t opcode_source[] = {
		{"pall", pall_m},
		{"pint", pint_m},
		{"pop", pop_m},
		{"swap", swap_m},
		{"add", add_m},
		{"sub", sub_m},
		{"div", div_m},
		{"mul", mul_m},
		{"push", push_m},
		{"mod", mod_m},
		{"pchar", pchar_m},
		{"pstr", pstr_m},
		{"rotl", rotl_m},
		{"rotr", rotr_m},
		{NULL, NULL}};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	bytecodes = fopen(argv[1], "r");
	if (bytecodes == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(buffer, sizeof(buffer), bytecodes))
	{
		index++;
		op_code = strtok(buffer, "\n ");

		if (op_code == NULL || op_code[0] == '#')
			continue;

		if (strcmp(op_code, "queue") == 0)
		{
			StackQueue.status = 100;
			continue;
		}

		if (strcmp(op_code, "stack") == 0)
		{
			StackQueue.status = 200;
			continue;
		}

		if (strcmp(op_code, "push") == 0)
		{
			operand = strtok(NULL, " \n");
			if (operand == NULL || (atoi(operand) == 0 && operand[0] != '0'))
			{
				fprintf(stderr, "L%u: usage: push integer\n", index);
				exit(EXIT_FAILURE);
			}

			opcode_source[8].f(&unstable_stack, atoi(operand));
			continue;
		}

		index_scnd = 0;
		while (opcode_source[index_scnd].opcode != NULL)
		{
			if (strcmp(op_code, opcode_source[index_scnd].opcode) == 0)
			{

				opcode_source[index_scnd].f(&unstable_stack, index);
				break;
			}
			index_scnd++;
		}
		if (index_scnd > 13)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", index, op_code);
			exit(EXIT_FAILURE);
		}
	}

	fclose(bytecodes);
	free(unstable_stack);
	return (0);
}

/**
 * pint_m - Prints value of first item on stack
 * @stack: Doubly Linked list
 * @line_number:  Line number
 */
void pint_m(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%u: can't pint_func, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
