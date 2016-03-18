//
// Created by Gerard on 18-3-2016.
//

#include "Array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* createArray(int nElle)
{
    int* array = (int*)malloc(nElle * sizeof(int));
    for(int i=0;i< nElle; i++)
        array[i] = 0;

    return array;
}
int* createRandomArray(int nElle)
{
    int* array = (int*)malloc(nElle * sizeof(int));

    for(int i=0;i< nElle; i++)
        array[i] = rand() % (2*nElle);

    return array;
}
void destroyArray(int **a)
{
    if(*a) {
        free(*a);
        *a = 0;
    }
}
void displayArray(int *a, int nElles)
{
    if(a)
    {
        if(nElles > MAXDISP)
        {
            printf("%d, %d...(%d)...%d, %d", a[0], a[1], nElles, a[nElles-2], a[nElles-1]);
        }
        else {
            for (int i = 0; i < nElles; i++) {
                printf("%d, ", a[i]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Empty array \n");
    }
}

void simpleSort(int *a, int nElles)
{
    // Loop up until last elements
    for(int i=0; i< nElles-1; i++)
    {
        // Match with remaining element.
        for(int j=i+1; j < nElles; j++)
        {
            // If next element is smaller
            if(a[j] < a[i]) {
                // Swap
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void simpleSortGeneric(void *a,int nEle, int elemSize, int (*compare)(void*,void*))
{
    int last = nEle * elemSize;
    void *tmp = malloc(elemSize);

    // Loop up until last elements
    for(int i=0; i< last-elemSize; i+= elemSize)
    {
        // Match with remaining element.
        for(int j=i+elemSize; j < last; j+=elemSize)
        {
            // If next element is smaller
            if( compare( a+i, a+j) > 0) {
                // Swap
                memcpy(tmp, a+j, elemSize);
                memcpy(a+j, a+i, elemSize);
                memcpy(a+i, tmp, elemSize);
            }
        }
    }
    free(tmp);
}