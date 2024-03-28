#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* Struct for the stack */
typedef struct Stack {
    int data;
    struct Stack *next;
} Stack;

/* Function prototypes */
void push(Stack **stack, int value);
void pall(Stack *stack);

#endif /* MONTY_H */

