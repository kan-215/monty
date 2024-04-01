#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack
 * @s: Pointer to the stack
 * @line_number: Line number where the opcode appears
 *
 * Description: This function swaps the top two elements of the stack.
 * If the stack contains less than two elements, it prints an error message
 * and exits with EXIT_FAILURE status.
 */
void swap(Stack *s, int line_number)
{
	int temp;

	if (s->top < 2)
	{
	fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
	exit(EXIT_FAILURE);
	}

	temp = s->stack[s->top - 1];
	s->stack[s->top - 1] = s->stack[s->top - 2];
	s->stack[s->top - 2] = temp;
}
