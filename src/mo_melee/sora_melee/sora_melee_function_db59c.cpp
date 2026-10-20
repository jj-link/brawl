#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_84598(void* p, s32 n);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);

void* fn_27_DB59C(void* p, s32 flag) {
    if (p) {
        __destroy_arr((u8*)p + 0xC, (void (*)(void*, int))fn_27_84598, 0xC, 4);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
