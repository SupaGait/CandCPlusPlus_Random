//
// Created by Gerard on 18-3-2016.
//

#include <stdlib.h>
#include "Stack.h"

Stack* createStack(int capacity)
{
    // Create stack
    Stack *stack = (Stack*) malloc( sizeof(Stack) );

    // Initialize the stack
    stack->capacity = capacity;
    stack->position = -1;
    stack->data = (int*) malloc( capacity * sizeof(int) );
}

void destroyStack(Stack **s)
{
    if(*s)
    {
        free((*s)->data);
        free(*s);
        *s = nullptr;
    }
}

int top(Stack *s)
{
    if(s && !isEmpty(s))
    {
        return s->data[s->position];
    }
}
void pop(Stack *s)
{
    if(s && s->position > -1)
    {
        // Remove last
        s->position--;
    }
}
void push(Stack *s, int i)
{
    if(s && !isFull(s))
    {
        // Assign the data
        s->data[++s->position] = i;
    }
}
int isEmpty(Stack *s)
{
    if(!s)
        return -1;

    return (s->position > -1)? 0:1;
}
int isFull(Stack *s)
{
    if(!s)
        return -1;

    return (s->position < s->capacity)? 0:1;
}

