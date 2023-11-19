#include "monty.h"


/**
 * pushInt - Pushes integer onto the stack.
 * @stack: A pointer to the top of stack.
 * @line_number: The line number.
 */
void pushInt(stack_t **stack, unsigned int line_number)
{
	stack_t *clean_node;
	int i;

	if (token[1] == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	i = atoi(token[1]);
	if (i == 0 && token[1][0] != '0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	clean_node = malloc(sizeof(stack_t));
	if (clean_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	clean_node->n = i;
	clean_node->prev = NULL;
	clean_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = clean_node;
	*stack = clean_node;
}
/**
 * prntall - Prints all the elements.
 * @stack: Pointer to the top of stack.
 * @line_number: The line number.
 */

void prntall(stack_t **stack, unsigned int line_number)
{
	stack_t *now = *stack;

	(void)line_number;

	while (now != NULL)
	{
		printf("%d\n", now->n);
		now = now->next;
	}
}

/**
 * prntInt - Prints the value at the top.
 * @stack: Pointer to the top of stack.
 * @line_number: The line number.
 */
void prntInt(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * PoP - Pops the top element of the stack.
 * @stack: Pointer to top of stack.
 * @line_number: The line number.
 */
void PoP(stack_t **stack, unsigned int line_number)
{
	stack_t *numb;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	numb = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(numb);
}

/**
 * SwaP - Swaps the top two elements of stack.
 * @stack: Pointer to the top of stack.
 * @line_number: The line number.
 */
void SwaP(stack_t **stack, unsigned int line_number)
{
	stack_t *numb;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	numb = (*stack)->next;
	(*stack)->next = numb->next;
	if (numb->next != NULL)
		numb->next->prev = *stack;
	numb->prev = NULL;
	numb->next = *stack;
	(*stack)->prev = numb;
	*stack = numb;
}
