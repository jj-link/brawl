#include <types.h>
#pragma force_active on

extern "C" void* fn_27_84198(void* p, s32 n);
extern "C" void __destroy_arr(void* p, void (*dtor)(void*, int), unsigned long elemSize, unsigned long count);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_27_DBBB4(void* p, s32 flag) {
    if (p) {
        __destroy_arr((u8*)p + 0xC, (void (*)(void*, int))fn_27_84198, 0xC, 3);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
