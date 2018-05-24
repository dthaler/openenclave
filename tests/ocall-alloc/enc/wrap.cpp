// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

/*
    Wrapper functions for host allocation tracking and atexit handling.
 */

#include <openenclave/bits/atexit.h>
#include <openenclave/bits/tests.h>
#include <openenclave/enclave.h>
#include <map>
#include <vector>
// And local wrap
#include "wrap.h"

static struct
{
    std::vector<std::pair<void (*)(void*), void*>> exits;
    std::map<void*, size_t> allocations;
} stats;

OE_EXTERNC_BEGIN

int My__cxa_atexit(void (*func)(void*), void* arg, void* dso_handle)
{
    stats.exits.push_back({func, arg});
    return __cxa_atexit(func, arg, dso_handle);
}

void* MyOE_HostMalloc(size_t size)
{
    void* p;

    p = OE_HostMalloc(size);
    if (p)
    {
        auto ins = stats.allocations.insert(std::pair<void*, size_t>(p, size));
        OE_TEST(ins.second == true);
    }
    return p;
}

void MyOE_HostFree(void* ptr)
{
    if (ptr)
        OE_TEST(stats.allocations.erase(ptr) == 1);
    OE_HostFree(ptr);
}

OE_EXTERNC_END

size_t MyGetAllocationCount()
{
    return stats.allocations.size();
}

size_t MyGetAllocationBytes()
{
    size_t s = 0;
    for (auto e : stats.allocations)
        s += e.second;
    return s;
}

void MyExit()
{
    for (auto e : stats.exits)
        e.first(e.second);
}