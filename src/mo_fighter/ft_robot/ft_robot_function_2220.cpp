#include <stddef.h>
#pragma force_active on

extern "C" {
void __dl__FPv(void* p);
}

extern "C" void* fn_120_2220(void* self, short flags)
{
    if (self != NULL && flags > 0) {
        __dl__FPv(self);
    }
    return self;
}
