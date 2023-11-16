#include "monty.h"

/**
 * push_m - Adds node to the stack
 * @stack: head
 * @line_number: line number
 */
void push_m(stack_t **stack, unsigned int line_number)
{

	int n = 0;

	if (globalNode.stringToken == NULL)
	{
		free_dlistint(*stack);
		stderr_int(line_number);
	}
	if (!_isdigit() || stack == NULL)
	{
		free_dlistint(*stack);
		stderr_int(line_number);
	}
	n = atoi(globalvar.stringToken);
	if (*stack  == NULL)
	{
		node_stackfirst(stack, n);
	}
	else
	{
		node_stackend(stack, n);
	}
}

/**
 * pall_m - Prints all the stack
 * @stack: head
 * @line_number: line number
 */
void pall_m(stack_t **stack, unsigned int line_number)
{

	stack_t *temp = NULL;


	if (*stack == NULL)
	{
		return;
	}
	if (*stack == NULL && line_number != 1)
	{
		freee_dlistint(*stack);
		freee_globalNodes();
		exit(EXIT_SUCCESS);
	}
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	while (temp->prev != NULL)
	{
		printf("%d", temp->n);
		temp = temp->prev;
		printf("\n");
	}
	printf("%d\n", temp->n);
}


/**
 * pint_m - Prints value of the stack
 * @stack: head
 * @line_number: line number
 */
void pint_m(stack_t **stack, unsigned int line_number)
{

	stack_t *temp = NULL;

	if (stack == NULL || *stack == NULL)
	{
		pint_e(line_number);
		return;
	}
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;

	printf("%d", temp->n);
	printf("\n");
}

/**
 * swap_m - switch the top two items of the stack
 * @stack: head
 * @line_number: line number
 */
void swap_m(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int a, m;

	if (*stack == NULL || stack == NULL)
		op_e(line_number, "swap");

	temp = (*stack)->next;
	if ((*stack)->next == NULL)
		op_e(line_number, "swap");
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	a = temp->n;
	m = temp->prev->n;
	temp->n = m;
	temp->prev->n = a;
}
/**
 * nop - does nothing
 * @stack: head
 * @line_number: line number
 */
void nop_m(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
