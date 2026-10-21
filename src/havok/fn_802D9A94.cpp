#include <types.h>
#pragma force_active on

extern "C" {
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void fn_802D9AD8(void*);
extern float lbl_80532A10[16];
extern u8 lbl_805A0F18;
}

extern "C" void fn_802D9A94() {
    __construct_array(lbl_80532A10, fn_802D9AD8, 0, 0x20, 2);
    lbl_805A0F18 = 0;
}

__declspec(section ".ctors") extern void* const fn_802D9A94_ctor = (void*)fn_802D9A94;
