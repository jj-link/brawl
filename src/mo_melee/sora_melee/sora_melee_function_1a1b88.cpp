#include <types.h>
#pragma force_active on

extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void* fn_27_AB510(void* p, s32 n);
}

struct fn_27_1A1B88_Obj {
    u8 pad[0xC];
    u8 arr[0x20];
};

extern "C" fn_27_1A1B88_Obj* fn_27_1A1B88(fn_27_1A1B88_Obj* p, s32 n) {
    if (p) {
        __destroy_arr(p->arr, (void (*)(void*, int))fn_27_AB510, 0x10, 2);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
