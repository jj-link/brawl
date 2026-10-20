#include <types.h>
#pragma force_active on

extern "C" void fn_27_C940C(void);
extern "C" void __destroy_arr(void* p, void (*dtor)(void*), unsigned long size, unsigned long count);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_27_1E0B24(void* self, s32 del) {
    if (self) {
        if ((u8*)self + 0x10 != 0) {
            __destroy_arr((u8*)self + 0x1c, (void (*)(void*))fn_27_C940C, 0x10, 6);
        }
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
