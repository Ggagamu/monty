#include "monty.h"

/**
 * push_m - Adds to the stack
 * @stack: Stack
 * @operand: Data
 */

void push_m(stack_t **stack, unsigned int operand)
{
	stack_t *temp_stack, *new;

	new = *stack;

	temp_stack = malloc(sizeof(stack_t));
	if (!temp_stack)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	temp_stack->prev = NULL;
	temp_stack->n = operand;
	temp_stack->next = NULL;

	if (*stack)
	{
		if (StackQueue.status == 200)
		{
			(*stack)->prev = temp_stack;
			temp_stack->next = *stack;
			*stack = temp_stack;
		}
		else if (StackQueue.status == 100)
		{
			while (new->next != NULL)
				new = new->next;
			new->next = temp_stack;
			temp_stack->prev = new;
		}
	}
	else
		*stack = temp_stack;

	free(temp_stack);
}

/**
 * pall_m - prints value of all items of the stack
 * @stack: Stack
 * @operand: Value
 */
void pall_m(stack_t **stack, unsigned int operand)
{
	stack_t *temp_stack;

	temp_stack = *stack;
	(void)operand;

	while (temp_stack)
	{
		printf("%d\n", temp_stack->n);
		temp_stack = temp_stack->next;
	}
}


/**
 * pop_m - Pop the topmost element of the stack
 * @stack: Stack
 * @line_number: Line number instruction
 */

void pop_m(stack_t **stack, unsigned int line_number)
{
	stack_t *unstable_stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	unstable_stack = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(unstable_stack);
}

/**
 * swap_m - Switch the two most items
 * @stack: Stack
 * @line_number: Line number
 */

void swap_m(stack_t **stack, unsigned int line_number)
{
	int i;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	i = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = i;
}
