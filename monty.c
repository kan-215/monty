#include "monty.h"

/**
 * push -fuvtion tht Pushes an element onto the stack.
 * @stack: Double pointer to the head node of the stack.
 * @line_number: The line number being executed from the script file.
 * @value: The value to be pushed to the stack.
 */
void push(stack_t **stack, unsigned int line_number, int value)
{
	stack_t *new_node;

	(void)line_number;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;

	if (*stack != NULL)
	{
	new_node->next = *stack;
	(*stack)->prev = new_node;
	}
	else
	{
	new_node->next = NULL;
	}

	*stack = new_node;
}

/**
 * pall -function Prints all the values on the stack, starting from the top.
 * @stack: Double pointer to the head node of the stack.
 * @line_number: The line number being executed from the script file.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;

	current = *stack;

	while (current != NULL)
	{
	printf("%d\n", current->n);
	current = current->next;
	}
}
