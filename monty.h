#ifndef MONTY_H
#define MONTY_H

#define STACK_SIZE 1024

/**
 * struct Stack_s - Stack structure
 * @stack: array of integers acting as a stack
 * @top: index of the top element in the stack
 */
typedef struct Stack_s {
    int stack[STACK_SIZE];
    int top;
} Stack;

/* Function prototypes */
void push(Stack *s, int value, int line_number);
void pall(Stack *s);

#endif /* MONTY_H */
