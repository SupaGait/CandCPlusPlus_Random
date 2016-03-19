//
// Created by Gerard on 18-3-2016.
//

#ifndef TEST_ARRAY_H
#define TEST_ARRAY_H

#define MAXDISP 100

/**
 * Create an array of int elements
 *  - Zero initialised
 */
int* createArray(int nElle);
/**
 * Create an array of int elements
 * - Random initialized
 */
int* createRandomArray( int nElle);
/**
 * Destroy the int array
 */
void destroyArray(int **a);
/**
 * Display array content
 */
void displayArray(int *a, int nElles);

/**
 * Simple inefficient sort
 */
void simpleSort(int *a, int nElles);

void simpleSortGeneric(void *a,unsigned int nEle, unsigned int elemSize, int(*compare)(const void*,const void*));

#endif //TEST_ARRAY_H
