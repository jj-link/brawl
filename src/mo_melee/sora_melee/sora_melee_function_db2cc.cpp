#include <types.h>
#pragma force_active on

extern "C" void* fn_27_84358(void* p, s32 n);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" {
void* fn_27_DB2CC(void* self, s32 n) {
    if (self) {
        __destroy_arr((u8*)self + 0xc, (void (*)(void*, int))fn_27_84358, 0xc, 1);
        if (n > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
