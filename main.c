#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * cleanup_stack - Frees memory allocated for the stack
 * @stack: Pointer to the top of the stack
 */
void cleanup_stack(Stack *stack)
{
	while (stack != NULL)
	{
		Stack *temp = stack;
		stack = stack->next;
		free(temp);
	}
}

/**
 * main - Entry point of the Monty interpreter
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	FILE *file;
	Stack *stack = NULL;
	char opcode[10];
	int value;
	int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Unable to open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	while (fscanf(file, "%s", opcode) != EOF)
	{
		line_number++;

		if (strcmp(opcode, "push") == 0)
		{
			if (fscanf(file, "%d", &value) != 1)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				fclose(file);
				cleanup_stack(stack);
				return (EXIT_FAILURE);
			}
			push(&stack, value);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(stack);
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			fclose(file);
			cleanup_stack(stack);
			return (EXIT_FAILURE);
		}
	}

	fclose(file);
	cleanup_stack(stack);

	return (EXIT_SUCCESS);
}
