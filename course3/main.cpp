//
// Created by Gerard on 25-3-2016.
//

#include <stdio.h>
#include "StackLinkedGeneric.h"

int main(int arc, char** args)
{
    int e1 = 1, e2=2;
    Status result;

    Stack *stack = createStack();
    if(!stack)
        return 1;

    // Add two elements
    result = push(stack,&e1);
    if(result)
    {
        fprintf(stderr, "%s\n", errorMessage(result));
        return 2;
    }
    result = push(stack,&e2);
    if(result)
    {
        fprintf(stderr, "%s\n", errorMessage(result));
        return 2;
    }

    // Display all the lements
    while (!isEmpty(stack)){
        printf("%d,", *((int*)(*stack)->element));
        pop(stack);
    }
    printf("\n");

    // Clean up and exit
    destroyStack(stack);
    return 0;
}