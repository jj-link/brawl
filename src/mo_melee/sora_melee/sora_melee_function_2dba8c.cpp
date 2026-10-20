#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_97968(void*, short);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void* fn_27_9FA50(void*, int);
void __dl__FPv(void*);

void* fn_27_2DBA8C(void* a, s32 b) {
    if (a) {
        fn_27_97968((unsigned char*)a + 0x58, -1);
        if (a && a)
            __destroy_arr((unsigned char*)a + 0xC, (void (*)(void*, int))fn_27_9FA50, 0x2C, 1);
        if (b > 0)
            __dl__FPv(a);
    }
    return a;
}
}
