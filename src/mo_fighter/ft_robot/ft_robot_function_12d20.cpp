#include <stddef.h>
#pragma force_active on

extern "C" void operator delete(void* p);

extern "C" void* fn_120_12D20(void* p, short flags)
{
    if (p != NULL && flags > 0) {
        operator delete(p);
    }
    return p;
}
