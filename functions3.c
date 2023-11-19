#include "monty.h"

/**
 * plus - Adds the top two elements of stack
 * @stack: Pointer to the stack
 * @line_number: Line number.
 */
void plus(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	PoP(stack, line_number);
}

/**
 * nope - Does not do anything.
 * @stack: Pointer to the stack.
 * @line_number: Line number.
 */
void nope(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
 * minus - Subtracts the top from the second
 * @stack: Pointer to the stack
 * @line_number: Line number
 */

void minus(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	PoP(stack, line_number);
}
/**
 * by - Divides the second from the top
 * @stack: Pointer to the stack
 * @line_number: Line number
 */

void by(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n /= (*stack)->n;
	PoP(stack, line_number);
}
