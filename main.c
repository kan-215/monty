#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

int main(void)
{
    Stack stack;
    char opcode[10];
    int value;
    int line_number = 0;

    stack.top = 0;

    while (scanf("%s", opcode) != EOF)
    {
        line_number++;
        if (strcmp(opcode, "push") == 0)
        {
            if (scanf("%d", &value) != 1)
            {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
            }
            push(&stack, value, line_number);
        }
        else if (strcmp(opcode, "pall") == 0)
        {
            pall(&stack);
        }
        else
        {
            fprintf(stderr, "L%d: Unknown opcode: %s\n", line_number, opcode);
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}
