//
// Created by Gerard on 18-3-2016.
//

#ifndef TEST_STACK_H
#define TEST_STACK_H


typedef struct _Stack
{
    int capacity;
    int* data;
    int position;
}Stack;


Stack* createStack(int capacity);
void destroyStack(Stack **s);

int top(Stack *s);
void pop(Stack *s);
void push(Stack *s, int i);
int isEmpty(Stack *s);
int isFull(Stack *s);


#endif //TEST_STACK_H
