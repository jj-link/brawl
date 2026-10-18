#include <stddef.h>
#pragma force_active on

extern "C" {
void operator delete(void* p);
}

extern "C" void* fn_120_13A48(void* self, short flags)
{
    if (self != NULL && flags > 0) {
        operator delete(self);
    }
    return self;
}
