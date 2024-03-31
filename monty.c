#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * push - Pushes an element onto the stack
 * @s: Pointer to the stack
 * @value: Value to be pushed
 * @line_number: Line number where the opcode appears
 *
 * Description: This function pushes an element onto the stack.
 */
void push(Stack *s, int value, int line_number)
{
	if (s->top == STACK_SIZE)
	{
	fprintf(stderr, "L%d: Stack overflow\n", line_number);
	exit(EXIT_FAILURE);
	}
	s->stack[s->top++] = value;
}

/**
 * pall - Prints all the values on the stack
 * @s: Pointer to the stack
 *
 * Description: This function prints all the values on the stack.
 */
void pall(Stack *s)
{
	int i;

	if (s->top == 0)
	{
	return;
	}

	for (i = s->top - 1; i >= 0; i--)
	{
	printf("%d\n", s->stack[i]);
	}
}
