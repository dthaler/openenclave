// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#ifndef _ARGS_H
#define _ARGS_H

#include <openenclave/bits/types.h>

#define MAX_ADDRESSES 64

typedef struct _Args
{
    /* backtrace() addresses */
    void* buffer[MAX_ADDRESSES];
    int size;
} Args;

#endif /* _ARGS_H */
