#include <types.h>
#pragma force_active on

extern "C" void fn_801AAB2C(void* obj, void* owner);
extern "C" char lbl_80466270[];

extern "C" void* fn_801AC13C(void* a, void* b, void* c, void* d) {
    fn_801AAB2C(a, b);
    *(void**)a = lbl_80466270;
    *(void**)((char*)a + 0xdc) = c;
    *(void**)((char*)a + 0xe0) = d;
    *(s32*)((char*)a + 0xe4) = 0;
    *(s32*)((char*)a + 0xcc) |= 0x60000000;
    return a;
}