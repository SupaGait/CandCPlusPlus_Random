//
// Created by Gerard on 25-3-2016.
//

#ifndef TEST_GENERICSTACK_H
#define TEST_GENERICSTACK_H

#include "status.h"

typedef struct Box {
    struct Box *next;
    char value[1];
} Box;

typedef struct {
    Box *head, *available;
    int elementSize;
} Stack;

Stack* createStack(unsigned int elementSize);
void destroyStack(Stack *s);
int isEmpty(Stack *s);
Status push(Stack *s, void* element);
Status pop(Stack *s);
Status top(Stack *s, void *element);


#endif //TEST_GENERICSTACK_H
