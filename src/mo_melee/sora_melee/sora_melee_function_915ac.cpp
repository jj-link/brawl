#include <types.h>
#pragma force_active on

extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void* fn_27_71BC(void* p, s32 n);
void* fn_27_915AC(void* p, long flag);
}

void* fn_27_915AC(void* p, long flag) {
    if (p) {
        __destroy_arr((char*)p + 0xC, (void (*)(void*, int))fn_27_71BC, 8, 0x1F4);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
