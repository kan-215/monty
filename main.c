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

        len = strlen(line);

        if (len > 0 && line[len - 1] == '\n')
        {
            line[len - 1] = '\0';
        }

        opcode = strtok(line, " ");
        arg = strtok(NULL, " ");

        if (opcode != NULL)
        {
            printf("%s", opcode); /* Print the opcode */
            if (arg != NULL)
            {
                printf(" %s", arg); /* Print the argument if it exists */
            }
            printf("$\n"); /* Add $ and newline */
            if (strcmp(opcode, "push") == 0 && arg != NULL)
            {
                int value = atoi(arg);
                push(&stack, line_number, value);
            }
            else if (strcmp(opcode, "pall") == 0)
            {
                pall(&stack, line_number);
            }
            else
            {
                fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
                fclose(file);
                return EXIT_FAILURE;
            }
        }
    }

    fclose(file);

    while (stack != NULL)
    {
        temp = stack;
        stack = stack->next;
        free(temp);
    }

    return EXIT_SUCCESS;
}
