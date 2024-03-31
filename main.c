#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[])
{
    FILE *file;
    stack_t *stack = NULL;
    char line[MAX_LINE_LENGTH];
    unsigned int line_number = 0;
    char *opcode, *arg;
    stack_t *temp;
    size_t len;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    while (fgets(line, sizeof(line), file) != NULL)
    {
        line_number++;

        /* Strip the end-of-line character */
        len = strlen(line);
        if (len > 0 && line[len - 1] == '\n')
        {
            line[len - 1] = '\0';
        }

        /* Parse the line to extract opcode and argument */
        opcode = strtok(line, " ");
        arg = strtok(NULL, " ");

        if (opcode != NULL)
        {
            /* Execute the opcode */
            if (strcmp(opcode, "push") == 0 && arg != NULL)
            {
                int value = atoi(arg);
                push(&stack, line_number, value);
            }
            else if (strcmp(opcode, "pint") == 0)
            {
                if (stack == NULL)
                {
                    fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
                    fclose(file);
                    return EXIT_FAILURE;
                }
                printf("%d\n", stack->n);
            }
            /* Add support for other opcodes as needed */
            else
            {
                fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
                fclose(file);
                return EXIT_FAILURE;
            }
        }
    }

    fclose(file);

    /* Free memory and exit */
    while (stack != NULL)
    {
        temp = stack;
        stack = stack->next;
        free(temp);
    }

    return EXIT_SUCCESS;
}
