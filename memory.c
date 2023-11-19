#include "monty.h"

/**
 * free_token - Frees array of tokens.
 * @token: The array.
 */
void free_token(char **token)
{
	int i;

	if (token != NULL)
	{
		for (i = 0; token[i] != NULL; i++)
		{
			free(token[i]);
		}
		free(token);
	}
}

/**
 * free_stack - Frees stack.
 * @stack: Pointer to top.
 */
void free_stack(stack_t *stack)
{
	stack_t *numb;

	while (stack != NULL)
	{
		numb = stack;
		stack = stack->next;
		free(numb);
	}
}
