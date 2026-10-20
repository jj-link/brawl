#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_7D898(void* p, int n);
void __destroy_arr(void* p, void (*dtor)(void*, int), unsigned long size, unsigned long count);
void __dl__FPv(void* p);

void* fn_27_1985B4(void* p, int n) {
    if (p) {
        __destroy_arr((u8*)p + 0xc, (void (*)(void*, int))fn_27_7D898, 0x1c, 4);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
