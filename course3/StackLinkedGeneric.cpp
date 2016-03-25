//
// Created by Gerard on 18-3-2016.
//

#include <stdlib.h>
#include "StackLinkedGeneric.h"

Stack* createStack()
{
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    if(!stack)
        return 0;

    *stack = nullptr;
    return stack;
}

void destroyStack(Stack *s)
{
    while(*s) {
        Stack tmp = *s;
        free(*s);
        *s = tmp;
    }
    free(s);
}

Status top(Stack *s, void **element)
{
    if(isEmpty(s))
        return ERROR_EMPTY;

    *element = (*s)->element ;
    return OK;
}

Status pop(Stack *s)
{
    if(isEmpty(s))
        return ERROR_EMPTY;

    // Other implementation then course 2, same effect
    Stack tmp = *s;
    *s = tmp->next;
    free(tmp);
    return OK;
}

Status push(Stack *s, void *element)
{
    Stack tmp = (Stack) malloc(sizeof(Box));
    if(!tmp)
        return ERROR_ALLOC;

    // Push the element
    tmp->element = element;
    tmp->next = *s;
    *s = tmp;
    return OK;
}

int isEmpty(Stack *s)
{
    return (*s) == nullptr;
}

int isFull(Stack *s)
{
    return 0;
}