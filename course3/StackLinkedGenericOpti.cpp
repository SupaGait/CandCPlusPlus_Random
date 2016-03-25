//
// Created by Gerard on 18-3-2016.
//

#include <stdlib.h>
#include "StackLinkedGeneric.h"

// Stack available for re-use
static Stack available = nullptr;
// Current stack size
static int counter = 0;

/**
 * Clean up the available Stack
 */
static void cleanUp()
{
    Stack tmp = available;
    while(tmp) {
        available = tmp->next;
        free(tmp);
        tmp = available;
    }
}
Stack* createStack()
{
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    if(!stack)
        return 0;

    *stack = nullptr;
    counter++;
    return stack;
}

void destroyStack(Stack *s)
{
    while(*s) {
        Stack tmp = (*s)->next;
        (*s)->next = available;

        available = *s;
        *s = tmp;
    }

    free(s);
    counter--;
    if(!counter)
        cleanUp();
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

    Stack tmp = (*s)->next;
    (*s)->next = available;
    available = *s;
    *s = tmp;
    return OK;
}

Status push(Stack *s, void *element)
{
    Stack tmp;
    if(available) {
        tmp = available;
        available = available->next;
    }
    else
        tmp = (Stack) malloc(sizeof(Box));
    if(!tmp)
        return ERROR_ALLOC;

    tmp->element = element;
    tmp->next = *s;

    *s = tmp;
    return  OK;
}

int isEmpty(Stack *s)
{
    return (*s) == nullptr;
}

int isFull(Stack *s)
{
    return 0;
}