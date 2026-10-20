#include <types.h>
#pragma force_active on

extern "C" void* fn_27_46B20(void* ptr, int size);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_19FB24(void* self, int shouldDelete) {
    if (self) {
        __destroy_arr((char*)self + 0xC, (void (*)(void*, int))fn_27_46B20, 0xB8, 2);
        if (shouldDelete > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
