#include "monty.h"


/* Function to push an element to the stack */
void push(Stack **stack, int value)
{
	Stack *new_node = malloc(sizeof(Stack));
	if (new_node == NULL) {
	fprintf(stderr, "Error: Unable to allocate memory\n");
	exit(EXIT_FAILURE);
	}
	new_node->data = value;
	new_node->next = *stack;
	*stack = new_node;
}

/* Function to print all the values on the stack */
void pall(Stack *stack)
{
	Stack *current = stack;
	while (current != NULL)
	{
	printf("%d\n", current->data);
	current = current->next;
	}
}
