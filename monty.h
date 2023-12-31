#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DELIMITERS "\t\n\r\a "


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;



/*GLOBAL VARIABLES*/
char **token;



/* TASKS FUNCTIONS */

int executeMontyCommands(FILE *file, stack_t **stack);
char **splitString(char *line);
void executeMontyInstruction(char *opcode, stack_t **stack, unsigned int line_number);
void free_token(char **token);
void free_stack(stack_t *stack);
void pushInt(stack_t **stack, unsigned int line_number);
void prntall(stack_t **stack, unsigned int line_number);
void prntInt(stack_t **stack, unsigned int line_number);
void PoP(stack_t **stack, unsigned int line_number);
void SwaP(stack_t **stack, unsigned int line_number);
void plus(stack_t **stack, unsigned int line_number);
void nope(stack_t **stack, unsigned int line_number);
void minus(stack_t **stack, unsigned int line_number);
void by(stack_t **stack, unsigned int line_number);
void multiply(stack_t **stack, unsigned int line_number);
void modulo(stack_t **stack, unsigned int line_number);
void prntchar(stack_t **stack, unsigned int line_number);
void prntstr(stack_t **stack, unsigned int line_number);
char **tokenize(char *input);


#endif
