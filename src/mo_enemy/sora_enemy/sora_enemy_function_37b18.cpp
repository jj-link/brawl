#include <types.h>

extern "C" void fn_41_2D244(void*, s16);
extern "C" void __dl__FPv(void*);

#pragma force_active on
extern "C" void* fn_41_37B18(void* self, s16 shouldDelete) {
    if (self != 0) {
        fn_41_2D244(reinterpret_cast<u8*>(self) + 4, -1);
        if (shouldDelete > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
