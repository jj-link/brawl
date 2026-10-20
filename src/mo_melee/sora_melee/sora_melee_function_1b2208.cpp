#include <types.h>
#pragma force_active on

extern "C" void* fn_27_844D8(void* ptr, int size);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_1B2208(void* self, int del) {
    if (self) {
        __destroy_arr((char*)self + 0xC, (void (*)(void*, int))fn_27_844D8, 0xC, 5);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
