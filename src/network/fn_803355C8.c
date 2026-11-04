#include <types.h>
#pragma force_active on

extern void* (*lbl_805A0F5C)(s32, void*, void*);

void* fn_803355C8(void* a0, void* a1) {
    void* res;
    void* r = lbl_805A0F5C(9, (void*)((char*)a1 + 0x20), a0);
    if (!r) {
        res = (void*)0;
    } else {
        res = (void*)((char*)r + 0x20);
        *(unsigned int*)r = 0x4457434d;
        *(void**)((char*)r + 4) = a1;
    }
    return res;
}