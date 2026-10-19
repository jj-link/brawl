#include <stddef.h>
#pragma force_active on

extern "C" void fn_40_3A10C(void* self, int flag);

extern "C" void* fn_40_3A2F4(void* self, int flag)
{
    if (self != NULL) {
        fn_40_3A10C(self, 0);
        if (flag > 0) {
            operator delete(self);
        }
    }
    return self;
}
