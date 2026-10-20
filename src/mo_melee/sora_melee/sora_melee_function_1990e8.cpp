#include <types.h>
#pragma force_active on

extern "C" void fn_27_A6978(void* p, int n);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_1990E8(void* self, int flag) {
    if (self) {
        __destroy_arr((char*)self + 0xC, fn_27_A6978, 0x24, 3);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
