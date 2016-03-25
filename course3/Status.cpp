//
// Created by Gerard on 25-3-2016.
//

#include "Status.h"

static const char* messages[] = { "memory allocation failed",
        "unable to close file",
        "unknown error" };

const char* errorMessage(Status s)
{
    if(s < 0 || s >= ERROR_UNKNOWN)
        return messages[ERROR_UNKNOWN];
    return messages[s];
}
