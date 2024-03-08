//
//  ADTErr.c
//  data structures in c
//

#include <stdio.h>

#include "ADTErr.h"

const char* ErrDescription[] =
{
    /* General ADT Errors - Description */
    "OK",
    "General Error",
    "Initialization error",
    "Allocation error",
    "ReAllocation error",
    "Underflow error",
    "Overflow error",
    "Wrong index",
    "Missing argument",
    "Not allowed duplicatios key",
    "Wrong Key",
    "Data Not Found",
};

void HandleErr(ADTErr errNum, char* msg)
{
    if (errNum)
    {
        printf("ErrNum=%d, ErrDescription=%s, msg=%s\n",
            errNum, ErrDescription[errNum], msg);
    }

}
