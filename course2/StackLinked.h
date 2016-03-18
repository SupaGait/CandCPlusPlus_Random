//
// Created by Gerard on 18-3-2016.
//

#ifndef TEST_STACKLINKED_H
#define TEST_STACKLINKED_H

typedef struct Box{
    int element;
    Box *next;
}Box,*Stack;

Stack* createStack();
void destroyStack(Stack *s);
int top(Stack *s);
void pop(Stack *s);
void push(Stack *s, int element);
int isEmpty(Stack *s);
int isFull(Stack *s);

#endif //TEST_STACKLINKED_H
