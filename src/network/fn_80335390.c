#include <types.h>
#pragma force_active on

extern void* (*lbl_805A0F5C)(void*, void*, s32);

void* fn_80335390(void* a0, void* a1) {
    void* res;
    void* r = lbl_805A0F5C(a0, (void*)((char*)a1 + 0x20), 0x20);
    if (r == 0) {
        res = (void*)0;
    } else {
        res = (void*)((char*)r + 0x20);
        *(unsigned int*)r = 0x4457434d;
        *(void**)((char*)r + 4) = a1;
    }
    return res;
}
