#include <types.h>
#pragma force_active on

extern void* (*lbl_805A0F5C)(s32, void*, s32);

void* fn_8033546C(void* a0) {
    void* res;
    void* r = lbl_805A0F5C(9, (void*)((char*)a0 + 0x20), 0x20);
    if (!r) {
        res = (void*)0;
    } else {
        res = (void*)((char*)r + 0x20);
        *(unsigned int*)r = 0x4457434d;
        *(void**)((char*)r + 4) = a0;
    }
    return res;
}
