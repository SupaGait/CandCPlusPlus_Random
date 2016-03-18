//
// Created by Gerard on 18-3-2016.
//

#include <stdlib.h>
#include "StackLinked.h"

Stack* createStack()
{
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    *stack = nullptr;
    return stack;
}

void destroyStack(Stack *s)
{
    // Assuming the stack is empty
    free(s);
}

int top(Stack *s)
{
    return (*s)->element;
}

void pop(Stack *s)
{
    Box* next = (*s)->next;
    free(*s);
    *s = next;
}

void push(Stack *s, int element)
{
    Box *tmp = *s;
    *s = (Box*) malloc(sizeof(Box));
    (*s)->element = element;
    (*s)->next = tmp;
}

int isEmpty(Stack *s)
{
    return (*s) == nullptr;
}

int isFull(Stack *s)
{
    return 0;
}