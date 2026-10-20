#include <types.h>
#pragma force_active on

extern "C" void* fn_27_84598(void* p, s32 n);
extern "C" void __destroy_arr(void* p, void (*dtor)(void*, int), unsigned long size, unsigned long count);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_27_DB614(void* p, s32 n) {
    if (p) {
        __destroy_arr((char*)p + 0xc, (void (*)(void*, int))fn_27_84598, 0xc, 3);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
