//
// Created by Gerard on 25-3-2016.
//

#include <stdlib.h>
#include <string.h>
#include "genericStackV2Opt.h"

Stack* createStack(unsigned int elementSize) {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    if(!stack)
        return 0;

    stack->head = nullptr;
    stack->elementSize = elementSize;
    stack->available = nullptr;
    return stack;
}

void destroyStack(Stack *s) {
    // free all next
    while (s->head) {
        Box *tmp = s->head->next;
        free(s->head);
        s->head = tmp;
    }

    // Free all available
    while(s->available){
        Box *tmp = s->available->next;
        free(s->available);
        s->available = tmp;
    }
    // free the stack
    free(s);
}

int isEmpty(Stack *s) {
    return (!s->head);
}

Status push(Stack *s, void *element) {
    Box *tmp;
    if(s->available) {
        tmp = s->available;
        s->available = s->available->next;
    }
    else {
        tmp = (Box*)malloc(sizeof(Box) + s->elementSize-1 );
        if(!tmp)
            return ERROR_ALLOC;
    }
    memcpy(tmp->value, element, s->elementSize);
    tmp->next = s->head;
    s->head = tmp;
    return OK;
}

Status pop(Stack *s) {
    if(!s->head)
        return ERROR_EMPTY;

    Box *tmp = s->head;
    s->head = s->head->next;
    tmp->next = s->available;
    s->available = tmp;

    return OK;
}

Status top(Stack *s, void *element) {
    if(!s->head)
        return ERROR_EMPTY;

    memcpy(element, s->head->value ,s->elementSize);
    return OK;
}
