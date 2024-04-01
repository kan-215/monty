#ifndef MONTY_H
#define MONTY_H

#define STACK_SIZE 1000

typedef struct Stack_s {
    int stack[STACK_SIZE];
    int top;
} Stack;

void push(Stack *s, int value, int line_number);
void pall(Stack *s);
void pint(Stack *s, int line_number);
void pop(Stack *s, int line_number);
void swap(Stack *s, int line_number);

#endif /* MONTY_H */
