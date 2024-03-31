#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * pint - Prints the value at the top of the stack
 * @s: Pointer to the stack
 * @line_number: Line number where the opcode appears
 *
 * Description: This function prints the value at the top of the stack,
 * followed by a new line. If the stack is empty, it prints an error message
 * and exits with EXIT_FAILURE status.
 */
void pint(Stack *s, int line_number)
{
	if (s->top == 0)
	{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	exit(EXIT_FAILURE);
	}
	printf("%d\n", s->stack[s->top - 1]);
}
