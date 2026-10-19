#include <stddef.h>
#pragma force_active on

extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void* fn_56_5A10(void* p, int flags);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_56_5A50(void* self, int flags) {
    if (self != NULL) {
        __destroy_arr((char*)self + 0xc, (void (*)(void*, int))fn_56_5A10, 8, 7);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
