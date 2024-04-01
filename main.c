#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

int main(int argc, char *argv[])
{
    FILE *file;
    Stack stack;
    char opcode[10];
    int value;
    int line_number = 0;
    char line[100];

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

    stack.top = 0;

    while (fgets(line, sizeof(line), file) != NULL)
    {
        line_number++;
        if (sscanf(line, "%s", opcode) != 1)
            continue;

        if (strcmp(opcode, "push") == 0)
        {
            if (sscanf(line, "%*s %d", &value) != 1)
            {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                fclose(file);
                return EXIT_FAILURE;
            }
            push(&stack, value, line_number);
        }
        else if (strcmp(opcode, "pall") == 0)
        {
            pall(&stack);
        }
        else if (strcmp(opcode, "pint") == 0)
        {
            pint(&stack, line_number);
        }
        else if (strcmp(opcode, "pop") == 0)
        {
            pop(&stack, line_number);
        }
        else
        {
            fprintf(stderr, "L%d: Unknown opcode: %s\n", line_number, opcode);
            fclose(file);
            return EXIT_FAILURE;
        }
    }

    fclose(file);
    return EXIT_SUCCESS;
}
