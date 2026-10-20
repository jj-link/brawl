#include <types.h>
#pragma force_active on

extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" void* fn_27_9F548(void* p, int n);

extern "C" void* fn_27_9ED0C(void* self, int doDelete) {
    if (self) {
        __destroy_arr((char*)self + 8, (void (*)(void*, int))fn_27_9F548, 0x10, 0xA);
        if (doDelete > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
