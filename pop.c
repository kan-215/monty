#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * pop - Removes the top element of the stack
 * @s: Pointer to the stack
 * @line_number: Line number where the opcode appears
 *
 * Description: This function removes the top element of the stack.
 * If the stack is empty, it prints an error message
 * and exits with EXIT_FAILURE status.
 */
void pop(Stack *s, int line_number)
{
	if (s->top == 0)
	{
	fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
	exit(EXIT_FAILURE);
	}
	s->top--;
}
