//
// Created by Gerard on 25-3-2016.
//

#include <stdio.h>

#if 0
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
        int *element;

        result = top(stack, (void**)&element );
        if(result) {
            fprintf(stderr, "%s\n", errorMessage(result));
            return 3;
        }

         printf("%d,", *element);

        //printf("%d,", *((int*)(*stack)->element));

        result = pop(stack);
        if(result) {
            fprintf(stderr, "%s\n", errorMessage(result));
            return 4;
        }
    }
    printf("\n");

    // Clean up and exit
    destroyStack(stack);
    return 0;
}
#endif


#if 0
#include "genericStack.h"
int main(int arc, char** args)
{
    int e1 = 1, e2=2;
    Status result;

    Stack *stack = createStack(sizeof(int));
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

    // Display all the elements
    while (!isEmpty(stack)){
        int element;

        result = top(stack, &element);
        if(result) {
            fprintf(stderr, "%s\n", errorMessage(result));
            return 3;
        }

        printf("%d,", element);

        result = pop(stack);
        if(result) {
            fprintf(stderr, "%s\n", errorMessage(result));
            return 4;
        }
    }
    printf("\n");

    // Clean up and exit
    destroyStack(stack);
    return 0;
}
#endif


#if 1
#include "genericStackV2Opt.h"
int main(int arc, char** args)
{
    int e1 = 1, e2=2;
    Status result;

    Stack *stack = createStack(sizeof(int));
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

    // Display all the elements
    while (!isEmpty(stack)){
        int element;

        result = top(stack, &element);
        if(result) {
            fprintf(stderr, "%s\n", errorMessage(result));
            return 3;
        }

        printf("%d,", element);

        result = pop(stack);
        if(result) {
            fprintf(stderr, "%s\n", errorMessage(result));
            return 4;
        }
    }
    printf("\n");

    // Clean up and exit
    destroyStack(stack);
    return 0;
}
#endif