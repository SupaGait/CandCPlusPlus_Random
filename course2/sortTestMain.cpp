//
// Created by Gerard on 19-3-2016.
//

//#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Array.h"
#include "sys/time.h"
int compareInt(const void *a, const void *b)
{
    return ( *((int*)a) - *((int*)b) );
}
int main(int argc, char **args)
{
    void (*f)(void*, unsigned int, unsigned int, int (*)(const void*,const void*));
    int size = 0;

    // Debug:
    printf("---------------\n");
    for (int i = 0; i < argc; ++i) {
        printf("%d: %s\n",i, args[i]);
    }
    printf("---------------\n");

    if(argc == 2)
    {
        // Our sort
        printf("Using simple sort\n");
        f = simpleSortGeneric;
        size = atoi( args[1] );
    }
    else if(argc == 3 && (strcmp(args[1], "-q")==0) )
    {
        // Quick sort
        printf("Using quick sort\n");
        f = qsort;
        size = atoi( args[2] );
    }
    else
    {
        printf("Input commands: [-q] size\n-q = qsort\nsize = nr of elements");
        return 0;
    }
    printf("nr of elements: %d\n", size);
    if(size < 1)
        return 0;

    /////////////////////////////////////////
    // Create
    int *ra = createRandomArray(size);


    struct timeval startTime;
    struct timeval endTime;

    //Sort
    gettimeofday(&startTime, nullptr);
    //time_t startTime = time(NULL);
    f(ra, size, sizeof(int), compareInt);
    gettimeofday(&endTime, nullptr);
    //time_t endTime = time(NULL);

    //printf("Diff time: %d", difftime(startTime, endTime) );
    unsigned long long t = 1000 * (endTime.tv_sec - startTime.tv_sec) + (endTime.tv_usec - startTime.tv_usec) / 1000;
    printf("%llu ms\n", t);

    //printf("Diff time: %lf\n", ((double)endTime - startTime) / CLOCKS_PER_SEC );

    destroyArray(&ra);

}
