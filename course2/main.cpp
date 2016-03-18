//
// Created by Gerard on 18-3-2016.
//

#include <stdio.h>
#include "Array.h"
#include "Stack.h"

// #define DO_TEST_ARRAY
#define DO_TEST_STACK

#ifdef DO_TEST_ARRAY
int main(){

    // Test Array
    int size;
    int *a, *ra;
    printf("array size?");
    scanf("%d", &size);

    a = createArray(size);
    ra = createRandomArray(size);

    // Display array content
    displayArray(a, size);
    displayArray(ra, size);

    // Sort random array and display
    simpleSort(ra,size);
    displayArray(ra, size);

    // Destroy the arrays
    destroyArray(&a);
    destroyArray(&ra);

    // Display the empty arrays
    displayArray(a, size);
    displayArray(ra, size);

    return 0;
}
#endif

#ifdef DO_TEST_STACK
int main()
{
    // Test Stack
    Stack* stack = createStack(10);
    printf("The stack is: %s\n", isEmpty(stack)?"Empty":"Not Empty");
    for (int i = 1; i < 6; ++i) {
        push(stack, i);
    }
    while ( !isEmpty(stack) )
    {
        // Print top and pop
        printf("%d ", top(stack));
        pop(stack);
    }
    printf("\n");
    destroyStack(&stack);

}

#endif