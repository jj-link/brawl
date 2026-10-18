#include <types.h>
#pragma force_active on

extern "C" void fn_123_496C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_123_490C(void* self, short deleting) {
    if (self != 0) {
        fn_123_496C(reinterpret_cast<u8*>(self) + 4, -1);
        if (deleting > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
