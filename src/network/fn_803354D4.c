#include <types.h>
#pragma force_active on

typedef void (*FreeFn)(s32, void*, s32);

extern void* (*lbl_805A0F5C)(s32, void*, void*);
extern FreeFn lbl_805A0F58;
extern void fn_8034F028(void*, const char*, u32);

void* fn_803354D4(void* a0, s32 a1) {
    void* base;
    s32 val;
    s32 len;
    char* p;

    base = lbl_805A0F5C(9, (void*)(a1 + 0x20), (void*)0x20);
    if (base == 0) {
        base = (void*)0;
    } else {
        *(u32*)base = 0x4457434d;
        *(s32*)((char*)base + 4) = a1;
        base = (void*)((char*)base + 0x20);
    }
    if (base == 0) {
        base = (void*)0;
    } else if (a0 != 0) {
        p = (char*)a0 - 0x20;
        val = *(s32*)(p + 4);
        if ((unsigned)val > (unsigned)a1) {
            len = a1;
        } else {
            len = val;
        }
        fn_8034F028(base, a0, len);
        if (a0 != 0) {
            lbl_805A0F58(9, p, val);
        }
    }
    return base;
}