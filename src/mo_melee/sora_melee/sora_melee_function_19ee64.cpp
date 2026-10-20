#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_CDA70(void* p, int flag);
void __destroy_arr(void* p, void (*dtor)(void*, int), unsigned long size, unsigned long count);
void __dl__FPv(void* p);

void* fn_27_19EE64(void* p, int flag) {
    if (p) {
        __destroy_arr((char*)p + 0xC, fn_27_CDA70, 0x10, 0xF);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
