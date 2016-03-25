//
// Created by Gerard on 18-3-2016.
//

#ifndef TEST_STACKLINKED_H
#define TEST_STACKLINKED_H

#include "Status.h"

typedef struct Box{
    void *element;
    Box *next;
}Box,*Stack;

Stack* createStack();
void destroyStack(Stack *s);
Status top(Stack *s, void **element);
Status pop(Stack *s);
Status push(Stack *s, void *element);
int isEmpty(Stack *s);
//int isFull(Stack *s);

#endif //TEST_STACKLINKED_H
