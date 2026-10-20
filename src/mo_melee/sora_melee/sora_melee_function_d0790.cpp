#include <types.h>
#pragma force_active on

extern "C" void fn_27_25290(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_D0790(void* self, int deleting) {
    if (self) {
        __destroy_arr((u8*)self + 0xC, fn_27_25290, 0x30, 0x2B);
        if (deleting > 0)
            __dl__FPv(self);
    }
    return self;
}
