//
// Created by Gerard on 25-3-2016.
//

#ifndef TEST_STATUS_H
#define TEST_STATUS_H

typedef enum{
    OK,
    ERROR_ALLOC,
    ERROR_OPEN,
    ERROR_EMPTY,
    ERROR_UNKNOWN
} Status;

const char* errorMessage(Status s);

#endif //TEST_STATUS_H
