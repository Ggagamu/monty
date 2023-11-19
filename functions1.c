#include "monty.h"

/**
 * multiply - Multiplies the second with the top.
 * @stack: Pointer to top of stack.
 * @line_number: The line number.
 */
void multiply(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}

/**
 * modulo - calculates the modulo of the second with the top element.
 * @stack: Pointer to the top of stack.
 * @line_number: The line number.
 */
void modulo(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n %= (*stack)->n;
	pop(stack, line_number);
}

/**
 * prntchar - Prints ASCII character of the top element.
 * @stack: Pointer to the top of stack.
 * @line_number: The line number.
 */
void prntchar(stack_t **stack, unsigned int line_number)
{
	int char_ASCII;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	char_ASCII = (*stack)->n;
	if (char_ASCII < 0 || 127 < char_ASCII)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (char)char_ASCII);
}

/**
 * prntstr - Prints the string from the top of the stack.
 * @stack: A pointer to the top of stack.
 * @line_number: The line number.
 */
void prntstr(stack_t **stack, unsigned int line_number)
{
	stack_t *numb = *stack;

	(void)line_number;
	if (numb == NULL)
	{
		printf("\n");
		return;
	}
	while (numb != NULL && numb->n != 0 && numb->n >= 0 && numb->n <= 127)
	{
		printf("%c", (char)numb->n);
		numb = numb->next;
	}
	printf("\n");
}
