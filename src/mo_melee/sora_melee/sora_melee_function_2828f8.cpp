#include <types.h>
#pragma force_active on

extern "C" {
extern u8 lbl_27_data_5E518[];
void fn_27_D2A0C(void* p);
void fn_27_AB510(void* p, s32 n);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
}

extern "C" {
void* fn_27_2828F8(void* p) {
    u32* w = (u32*)p;
    *(u8**)p = lbl_27_data_5E518 + 0;
    *(u8**)((u8*)p + 4) = lbl_27_data_5E518 + 0x48;
    w[2] &= 0xFFFF;
    __construct_array((u8*)p + 0xc, (void (*)(void*))fn_27_D2A0C, (void (*)(void*))fn_27_AB510, 0x10, 12);
    return p;
}
}
