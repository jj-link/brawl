#include <stddef.h>
#pragma force_active on

extern "C" {
void fn_68_A150(void* self, int flag);
}

extern "C" void* fn_68_100BC(void* self, int size)
{
    if (self != NULL) {
        fn_68_A150(self, 0);
        if (size > 0) {
            ::operator delete(self);
        }
    }
    return self;
}
