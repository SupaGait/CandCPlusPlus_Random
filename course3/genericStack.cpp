//
// Created by Gerard on 25-3-2016.
//

#include <stdlib.h>
#include <string.h>
#include "genericStack.h"

Stack* createStack(unsigned int elementSize) {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    if(!stack)
        return 0;

    stack->head = nullptr;
    stack->elementSize = elementSize;
    return stack;
}

void destroyStack(Stack *s) {
    if(s->head) {
        Box *tmp = s->head->next;
        while (tmp) {
            free(s->head);
            s->head = tmp;
        }
    }
    free(s);
}

int isEmpty(Stack *s) {
    return (!s->head);
}

Status push(Stack *s, void *element) {
    // Create box and the elements
    Box* newBox = (Box*)malloc(sizeof(Box) + s->elementSize-1 );
    if(!newBox)
        return ERROR_ALLOC;

    memcpy(newBox->value, element, s->elementSize);
    newBox->next = s->head;
    s->head = newBox;
    return OK;
}

Status pop(Stack *s) {
    if(!s->head)
        return ERROR_EMPTY;

    Box *tmp = s->head->next;
    free(s->head);
    s->head = tmp;
    return OK;
}

Status top(Stack *s, void *element) {
    if(!s->head)
        return ERROR_EMPTY;

    memcpy(element, s->head->value ,s->elementSize);
    return OK;
}
